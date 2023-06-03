// Generated by gencpp from file fiducial_msgs/Fiducial.msg
// DO NOT EDIT!


#ifndef FIDUCIAL_MSGS_MESSAGE_FIDUCIAL_H
#define FIDUCIAL_MSGS_MESSAGE_FIDUCIAL_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace fiducial_msgs
{
template <class ContainerAllocator>
struct Fiducial_
{
  typedef Fiducial_<ContainerAllocator> Type;

  Fiducial_()
    : fiducial_id(0)
    , direction(0)
    , x0(0.0)
    , y0(0.0)
    , x1(0.0)
    , y1(0.0)
    , x2(0.0)
    , y2(0.0)
    , x3(0.0)
    , y3(0.0)  {
    }
  Fiducial_(const ContainerAllocator& _alloc)
    : fiducial_id(0)
    , direction(0)
    , x0(0.0)
    , y0(0.0)
    , x1(0.0)
    , y1(0.0)
    , x2(0.0)
    , y2(0.0)
    , x3(0.0)
    , y3(0.0)  {
  (void)_alloc;
    }



   typedef int32_t _fiducial_id_type;
  _fiducial_id_type fiducial_id;

   typedef int32_t _direction_type;
  _direction_type direction;

   typedef double _x0_type;
  _x0_type x0;

   typedef double _y0_type;
  _y0_type y0;

   typedef double _x1_type;
  _x1_type x1;

   typedef double _y1_type;
  _y1_type y1;

   typedef double _x2_type;
  _x2_type x2;

   typedef double _y2_type;
  _y2_type y2;

   typedef double _x3_type;
  _x3_type x3;

   typedef double _y3_type;
  _y3_type y3;





  typedef boost::shared_ptr< ::fiducial_msgs::Fiducial_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fiducial_msgs::Fiducial_<ContainerAllocator> const> ConstPtr;

}; // struct Fiducial_

typedef ::fiducial_msgs::Fiducial_<std::allocator<void> > Fiducial;

typedef boost::shared_ptr< ::fiducial_msgs::Fiducial > FiducialPtr;
typedef boost::shared_ptr< ::fiducial_msgs::Fiducial const> FiducialConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fiducial_msgs::Fiducial_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fiducial_msgs::Fiducial_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::fiducial_msgs::Fiducial_<ContainerAllocator1> & lhs, const ::fiducial_msgs::Fiducial_<ContainerAllocator2> & rhs)
{
  return lhs.fiducial_id == rhs.fiducial_id &&
    lhs.direction == rhs.direction &&
    lhs.x0 == rhs.x0 &&
    lhs.y0 == rhs.y0 &&
    lhs.x1 == rhs.x1 &&
    lhs.y1 == rhs.y1 &&
    lhs.x2 == rhs.x2 &&
    lhs.y2 == rhs.y2 &&
    lhs.x3 == rhs.x3 &&
    lhs.y3 == rhs.y3;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::fiducial_msgs::Fiducial_<ContainerAllocator1> & lhs, const ::fiducial_msgs::Fiducial_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace fiducial_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::fiducial_msgs::Fiducial_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fiducial_msgs::Fiducial_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fiducial_msgs::Fiducial_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fiducial_msgs::Fiducial_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fiducial_msgs::Fiducial_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fiducial_msgs::Fiducial_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fiducial_msgs::Fiducial_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a0094064db6c7772c6b638a2dab17f42";
  }

  static const char* value(const ::fiducial_msgs::Fiducial_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa0094064db6c7772ULL;
  static const uint64_t static_value2 = 0xc6b638a2dab17f42ULL;
};

template<class ContainerAllocator>
struct DataType< ::fiducial_msgs::Fiducial_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fiducial_msgs/Fiducial";
  }

  static const char* value(const ::fiducial_msgs::Fiducial_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fiducial_msgs::Fiducial_<ContainerAllocator> >
{
  static const char* value()
  {
    return " # Details of a detected fiducial.\n"
"\n"
" int32 fiducial_id\n"
" int32 direction\n"
"\n"
" # vertices\n"
" float64 x0\n"
" float64 y0\n"
" float64 x1\n"
" float64 y1\n"
" float64 x2\n"
" float64 y2\n"
" float64 x3\n"
" float64 y3\n"
;
  }

  static const char* value(const ::fiducial_msgs::Fiducial_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fiducial_msgs::Fiducial_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.fiducial_id);
      stream.next(m.direction);
      stream.next(m.x0);
      stream.next(m.y0);
      stream.next(m.x1);
      stream.next(m.y1);
      stream.next(m.x2);
      stream.next(m.y2);
      stream.next(m.x3);
      stream.next(m.y3);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Fiducial_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fiducial_msgs::Fiducial_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fiducial_msgs::Fiducial_<ContainerAllocator>& v)
  {
    s << indent << "fiducial_id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.fiducial_id);
    s << indent << "direction: ";
    Printer<int32_t>::stream(s, indent + "  ", v.direction);
    s << indent << "x0: ";
    Printer<double>::stream(s, indent + "  ", v.x0);
    s << indent << "y0: ";
    Printer<double>::stream(s, indent + "  ", v.y0);
    s << indent << "x1: ";
    Printer<double>::stream(s, indent + "  ", v.x1);
    s << indent << "y1: ";
    Printer<double>::stream(s, indent + "  ", v.y1);
    s << indent << "x2: ";
    Printer<double>::stream(s, indent + "  ", v.x2);
    s << indent << "y2: ";
    Printer<double>::stream(s, indent + "  ", v.y2);
    s << indent << "x3: ";
    Printer<double>::stream(s, indent + "  ", v.x3);
    s << indent << "y3: ";
    Printer<double>::stream(s, indent + "  ", v.y3);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FIDUCIAL_MSGS_MESSAGE_FIDUCIAL_H
