// Generated by gencpp from file fiducial_slam/AddFiducialResponse.msg
// DO NOT EDIT!


#ifndef FIDUCIAL_SLAM_MESSAGE_ADDFIDUCIALRESPONSE_H
#define FIDUCIAL_SLAM_MESSAGE_ADDFIDUCIALRESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace fiducial_slam
{
template <class ContainerAllocator>
struct AddFiducialResponse_
{
  typedef AddFiducialResponse_<ContainerAllocator> Type;

  AddFiducialResponse_()
    {
    }
  AddFiducialResponse_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::fiducial_slam::AddFiducialResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fiducial_slam::AddFiducialResponse_<ContainerAllocator> const> ConstPtr;

}; // struct AddFiducialResponse_

typedef ::fiducial_slam::AddFiducialResponse_<std::allocator<void> > AddFiducialResponse;

typedef boost::shared_ptr< ::fiducial_slam::AddFiducialResponse > AddFiducialResponsePtr;
typedef boost::shared_ptr< ::fiducial_slam::AddFiducialResponse const> AddFiducialResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fiducial_slam::AddFiducialResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fiducial_slam::AddFiducialResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace fiducial_slam

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::fiducial_slam::AddFiducialResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fiducial_slam::AddFiducialResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fiducial_slam::AddFiducialResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fiducial_slam::AddFiducialResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fiducial_slam::AddFiducialResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fiducial_slam::AddFiducialResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fiducial_slam::AddFiducialResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::fiducial_slam::AddFiducialResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::fiducial_slam::AddFiducialResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fiducial_slam/AddFiducialResponse";
  }

  static const char* value(const ::fiducial_slam::AddFiducialResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fiducial_slam::AddFiducialResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
;
  }

  static const char* value(const ::fiducial_slam::AddFiducialResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fiducial_slam::AddFiducialResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AddFiducialResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fiducial_slam::AddFiducialResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::fiducial_slam::AddFiducialResponse_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // FIDUCIAL_SLAM_MESSAGE_ADDFIDUCIALRESPONSE_H
