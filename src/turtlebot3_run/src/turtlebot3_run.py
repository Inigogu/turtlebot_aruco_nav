#!/usr/bin/env python3

import rospy
import actionlib
from math import pi
from geometry_msgs.msg import Pose2D
from turtlebot3_msgs.msg import GoToPoseAction, GoToPoseGoal, GoToPoseFeedback, GoToPoseResult

class Controller():
    def __init__(self):

        rospy.init_node('turtlebot3_run')

        self.client = actionlib.SimpleActionClient('goToPose', GoToPoseAction)

        self.client.wait_for_server()

    def run(self):
        goal_pose = Pose2D()
        goal_pose.x = 0.0
        goal_pose.y = 0.0
        goal_pose.theta = 0.0

        STATE = 0

        success = False

        
        while not success:
            if STATE == 0:
                goal_pose.x = 2.0
                goal_pose.y = 0.0
                goal_pose.theta = pi / 2.0
            elif STATE == 1:
                goal_pose.x = 0.0
                goal_pose.y = 0.0
                goal_pose.theta = pi
            elif STATE == 2:
                goal_pose.x = 0.0
                goal_pose.y = 0.0
                goal_pose.theta = -pi / 2.0
            elif STATE == 3:
                goal_pose.x = 0.0
                goal_pose.y = 0.0
                goal_pose.theta = -pi 
            else:
                goal_pose.x = 0.0
                goal_pose.y = 0.0
                goal_pose.theta = 0.0

            goal = GoToPoseGoal(goal_pose2d = goal_pose)
            self.client.send_goal(goal = goal, feedback_cb = self.callback_feedback, active_cb = self.callback_active)
            self.client.wait_for_result()
            result = self.client.get_result()

            if result != None:
                if result.success:
                    if STATE < 4:
                        STATE += 1
                    else:
                        STATE = 0

    def callback_active(self):
        rospy.loginfo("Action server is processing the goal")

    def callback_feedback(self, feedback):
        rospy.loginfo("Feedback:%s" % str(feedback))

if __name__ == '__main__':
    try:
        controller = Controller()
        controller.run()
    except rospy.ROSInterruptException:
        pass
