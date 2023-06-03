#!/usr/bin/env python3

import rospy
import actionlib
from geometry_msgs.msg import Pose2D, Twist
from sensor_msgs.msg import LaserScan
from turtlebot3_msgs.msg import GoToPoseAction, GoToPoseFeedback, GoToPoseResult
from turtlebot3_bug2 import Bug2

PUB_RATE = 10
LINEAL_VEL = 0.1
GOAL_ANGLE_THRESHOLD = 0.17453292519943295
GOAL_DISTANCE_THRESHOLD = 0.1
SLOPE_ANGLE_THRESHOLD = 0.17453292519943295
WALL_DISTANCE_THRESHOLD = 0.1

class Navigator():
    def __init__(self):
        # Initialize goal_pose, current_pose, lidar and cmd_vel
        self.goal_pose = Pose2D()
        self.current_pose = Pose2D()
        self.lidar = LaserScan()
        self.cmd_vel = Twist()

        # Initialize publishers and subscribers
        self.pub = rospy.Publisher("/cmd_vel", Twist, queue_size=1)
        self.pose_sub = rospy.Subscriber("/super_pose", Pose2D, self.pose_callback)
        self.lidar_sub = rospy.Subscriber("/scan", LaserScan, self.lidar_callback)

        # Initialize node
        rospy.init_node("turtlebot3_navigation")

        # Initialize parameters
        if rospy.has_param('/turtlebot3_navigation/parameters/pub_rate'):
            self.pub_rate = rospy.get_param('/turtlebot3_navigation/parameters/pub_rate')
        else:
            self.pub_rate = PUB_RATE
        if rospy.has_param('/turtlebot3_navigation/parameters/lineal_vel'):
            self.lineal_vel = rospy.get_param('/turtlebot3_navigation/parameters/lineal_vel')
        else:
            self.lineal_vel = LINEAL_VEL

        # Initialize objects
        self.bug2 = Bug2()

        # Initialize action server
        self.feedback = GoToPoseFeedback()
        self.result = GoToPoseResult()
        self.action = actionlib.SimpleActionServer(name="goToPose", ActionSpec=GoToPoseAction, execute_cb=self.action_callback, auto_start=False)

        # Start code
        self.rate = rospy.Rate(self.pub_rate)
        self.action.start()
        rospy.spin()

    def pose_callback(self, data):
        self.current_pose = data

    def lidar_callback(self, data):
        self.lidar = data

    def action_callback(self, goal):
        success = False
        self.goal_pose = goal
        while not success:
            self.cmd_vel, success = self.bug2.run(self.current_pose, rospy.get_time(), self.lidar)
            self.feedback.current_pose2d = self.current_pose
            self.action.publish_feedback(self.feedback)
            self.pub.publish(self.cmd_vel)
            self.rate.sleep()
        if success:
            self.result.success = True
            self.action.set_succeeded(self.result)

if __name__ == '__main__':
    try:
        navigator = Navigator()
    except rospy.ROSInterruptException:
        pass