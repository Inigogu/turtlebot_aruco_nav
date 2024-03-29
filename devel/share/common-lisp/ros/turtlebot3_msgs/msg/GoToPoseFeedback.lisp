; Auto-generated. Do not edit!


(cl:in-package turtlebot3_msgs-msg)


;//! \htmlinclude GoToPoseFeedback.msg.html

(cl:defclass <GoToPoseFeedback> (roslisp-msg-protocol:ros-message)
  ((current_pose2d
    :reader current_pose2d
    :initarg :current_pose2d
    :type geometry_msgs-msg:Pose2D
    :initform (cl:make-instance 'geometry_msgs-msg:Pose2D)))
)

(cl:defclass GoToPoseFeedback (<GoToPoseFeedback>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GoToPoseFeedback>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GoToPoseFeedback)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot3_msgs-msg:<GoToPoseFeedback> is deprecated: use turtlebot3_msgs-msg:GoToPoseFeedback instead.")))

(cl:ensure-generic-function 'current_pose2d-val :lambda-list '(m))
(cl:defmethod current_pose2d-val ((m <GoToPoseFeedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot3_msgs-msg:current_pose2d-val is deprecated.  Use turtlebot3_msgs-msg:current_pose2d instead.")
  (current_pose2d m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GoToPoseFeedback>) ostream)
  "Serializes a message object of type '<GoToPoseFeedback>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'current_pose2d) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GoToPoseFeedback>) istream)
  "Deserializes a message object of type '<GoToPoseFeedback>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'current_pose2d) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GoToPoseFeedback>)))
  "Returns string type for a message object of type '<GoToPoseFeedback>"
  "turtlebot3_msgs/GoToPoseFeedback")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GoToPoseFeedback)))
  "Returns string type for a message object of type 'GoToPoseFeedback"
  "turtlebot3_msgs/GoToPoseFeedback")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GoToPoseFeedback>)))
  "Returns md5sum for a message object of type '<GoToPoseFeedback>"
  "453e73e119d11e0288a9d5ee55bcd755")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GoToPoseFeedback)))
  "Returns md5sum for a message object of type 'GoToPoseFeedback"
  "453e73e119d11e0288a9d5ee55bcd755")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GoToPoseFeedback>)))
  "Returns full string definition for message of type '<GoToPoseFeedback>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#feedback~%geometry_msgs/Pose2D current_pose2d~%~%================================================================================~%MSG: geometry_msgs/Pose2D~%# Deprecated~%# Please use the full 3D pose.~%~%# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.~%~%# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.~%~%~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GoToPoseFeedback)))
  "Returns full string definition for message of type 'GoToPoseFeedback"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#feedback~%geometry_msgs/Pose2D current_pose2d~%~%================================================================================~%MSG: geometry_msgs/Pose2D~%# Deprecated~%# Please use the full 3D pose.~%~%# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.~%~%# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.~%~%~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GoToPoseFeedback>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'current_pose2d))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GoToPoseFeedback>))
  "Converts a ROS message object to a list"
  (cl:list 'GoToPoseFeedback
    (cl:cons ':current_pose2d (current_pose2d msg))
))
