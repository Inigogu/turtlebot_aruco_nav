; Auto-generated. Do not edit!


(cl:in-package turtlebot3_msgs-msg)


;//! \htmlinclude GoToPoseResult.msg.html

(cl:defclass <GoToPoseResult> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass GoToPoseResult (<GoToPoseResult>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GoToPoseResult>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GoToPoseResult)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot3_msgs-msg:<GoToPoseResult> is deprecated: use turtlebot3_msgs-msg:GoToPoseResult instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <GoToPoseResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot3_msgs-msg:success-val is deprecated.  Use turtlebot3_msgs-msg:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GoToPoseResult>) ostream)
  "Serializes a message object of type '<GoToPoseResult>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GoToPoseResult>) istream)
  "Deserializes a message object of type '<GoToPoseResult>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GoToPoseResult>)))
  "Returns string type for a message object of type '<GoToPoseResult>"
  "turtlebot3_msgs/GoToPoseResult")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GoToPoseResult)))
  "Returns string type for a message object of type 'GoToPoseResult"
  "turtlebot3_msgs/GoToPoseResult")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GoToPoseResult>)))
  "Returns md5sum for a message object of type '<GoToPoseResult>"
  "358e233cde0c8a8bcfea4ce193f8fc15")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GoToPoseResult)))
  "Returns md5sum for a message object of type 'GoToPoseResult"
  "358e233cde0c8a8bcfea4ce193f8fc15")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GoToPoseResult>)))
  "Returns full string definition for message of type '<GoToPoseResult>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#result~%bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GoToPoseResult)))
  "Returns full string definition for message of type 'GoToPoseResult"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#result~%bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GoToPoseResult>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GoToPoseResult>))
  "Converts a ROS message object to a list"
  (cl:list 'GoToPoseResult
    (cl:cons ':success (success msg))
))
