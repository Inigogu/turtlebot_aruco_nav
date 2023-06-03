#!/usr/bin/env python3

from math import atan2, inf, pi, sqrt
from geometry_msgs.msg import Pose2D, Twist
from turtlebot3_pid import PID

KP = 0.1
KI = 0.001
KD = 0.01
MIN_VAL = -0.3
MAX_VAL = 0.3

class Bug2():
    def __init__(self):
        self.goal_distance_threshold = 0
        self.goal_angle_threshold = 0
        self.goal_slope_threshold = 0

        self.goal = Pose2D()
        self.current_pose = Pose2D()

        self.lineal_vel = 0.3

        self.goal_slope = self.calculate_slope()
        self.current_slope = self.calculate_slope()

        self.turn_angle_direction = 0
        self.turn_angle_objective = 0

        self.go_to_goal_PID = PID(self.goal_slope, KP, KI, KD, MIN_VAL, MAX_VAL)
        self.follow_wall_PID = PID(0.5, KP, KI, KD, MIN_VAL, MAX_VAL)
        self.cmd_vel_out = Twist()

        # Initialize state machine ["go_to_goal", "follow_wall", "align_angle", "turn", "halt"]
        self.state = "halt"
        self.prev_state = "go_to_goal"

    def calculate_euclidean_distance(self):
        return sqrt((self.goal.y - self.current_pose.y)**2+(self.goal.x-self.current_pose.y)**2)
    
    def calculate_slope(self):
        return atan2(self.goal.y - self.current_pose.y, self.goal.x - self.current_pose.y)
    
    def check_for_wall(self, lidar):
        for i in range(-5,5):
            if lidar.ranges[i] != inf:
                if lidar.ranges[i] <= 0.5:
                    return True
        return False
    
    def set_current_state(self, distance_diff, angle_diff, slope_diff, lidar):
        if self.state == "halt":
            self.state = self.prev_state
        elif self.state == "align_angle":
            self.prev_state = "align_angle"
            self.state = "turn"
        elif self.state == "go_to_goal":
            if distance_diff <= self.goal_distance_threshold:
                self.state = "align_angle"
            if self.check_for_wall(lidar):
                self.state = "turn"
                self.turn_angle_direction = -1
                self.turn_angle_objective = self.current_pose.theta - 1.5708
                self.prev_state = "follow_wall"
        elif self.state == "follow_wall":
            if distance_diff <= self.goal_distance_threshold:
                self.state = "align_angle"
            elif slope_diff <= self.goal_slope_threshold:
                self.state = "go_to_goal"
            if self.check_for_wall(lidar):
                self.state = "turn"
                self.turn_angle_direction = -1
                self.turn_angle_objective = self.current_pose.theta - 1.5708
        elif self.state == "turn":
            if self.current_pose.theta <= self.turn_angle_objective + self.goal_angle_threshold or self.current_pose.theta >= self.turn_angle_objective - self.goal_angle_threshold:
                self.state = self.prev_state

    def turn(self, direction, objective):
        self.turn_angle_direction = direction
        self.turn_angle_objective = objective

    def go_to_goal(self, current_value, current_time):
        self.cmd_vel_out.linear.x = self.lineal_vel
        self.cmd_vel_out.angular.z = self.go_to_goal_PID.calculate_current_PID_gains(current_value, current_time)

    def follow_wall(self,current_time, lidar):
        if lidar.ranges[90] == inf:
            self.cmd_vel_out.angular.z = 0.3
        else: 
            self.cmd_vel_out.angular.z = self.follow_wall_PID.calculate_current_PID_gains(lidar.ranges[90], current_time)
        self.cmd_vel_out.linear.x = self.lineal_vel

    def align_angle(self, angle_diff):
        u_diff = self.goal.theta - self.current_pose.theta
        if angle_diff > pi and  u_diff > 0:
            direction = -1
        elif angle_diff > pi and  u_diff < 0:
            direction = 1
        elif angle_diff < pi and u_diff < 0:
            direction = -1
        else: 
            direction = 1
        self.turn(direction, self.current_pose.theta + (angle_diff * direction))

    def halt(self):
        self.cmd_vel_out.linear.x = 0
        self.cmd_vel_out.angular.z = 0

    def run(self, current_pose, current_time, lidar):
        self.current_pose = current_pose
        self.current_slope = self.calculate_slope()
        distance_diff = self.calculate_euclidean_distance()
        angle_diff = abs(self.goal.theta - self.current_pose.theta)
        slope_diff = abs(self.goal_slope - self.current_slope)
        if distance_diff <= self.goal_distance_threshold and angle_diff < self.goal_angle_threshold:
            success = True
            self.state = "halt"
            self.halt()
        else:
            success = False
            if self.state == "halt":
                self.halt()
            elif self.state == "align_angle":
                self.align_angle(angle_diff)
            elif self.state == "turn":
                self.turn(self.turn_angle_direction, self.turn_angle_objective)
            elif self.state == "go_to_goal":
                self.go_to_goal(self.current_slope, current_time)
            elif self.state == "follow_wall":
                self.follow_wall()
            self.set_current_state(distance_diff, angle_diff, slope_diff, lidar)
        return (self.cmd_vel_out, success)