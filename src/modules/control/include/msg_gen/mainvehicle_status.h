// Generated by gencpp from file msg_gen/mainvehicle_status.msg
// DO NOT EDIT!


#ifndef MSG_GEN_MESSAGE_MAINVEHICLE_STATUS_H
#define MSG_GEN_MESSAGE_MAINVEHICLE_STATUS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace msg_gen
{
template <class ContainerAllocator>
struct mainvehicle_status_
{
  typedef mainvehicle_status_<ContainerAllocator> Type;

  mainvehicle_status_()
    : mainVehicleId(0)
    , mainVehicleStatus(0)  {
    }
  mainvehicle_status_(const ContainerAllocator& _alloc)
    : mainVehicleId(0)
    , mainVehicleStatus(0)  {
  (void)_alloc;
    }



   typedef int32_t _mainVehicleId_type;
  _mainVehicleId_type mainVehicleId;

   typedef int32_t _mainVehicleStatus_type;
  _mainVehicleStatus_type mainVehicleStatus;





  typedef boost::shared_ptr< ::msg_gen::mainvehicle_status_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::msg_gen::mainvehicle_status_<ContainerAllocator> const> ConstPtr;

}; // struct mainvehicle_status_

typedef ::msg_gen::mainvehicle_status_<std::allocator<void> > mainvehicle_status;

typedef boost::shared_ptr< ::msg_gen::mainvehicle_status > mainvehicle_statusPtr;
typedef boost::shared_ptr< ::msg_gen::mainvehicle_status const> mainvehicle_statusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::msg_gen::mainvehicle_status_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::msg_gen::mainvehicle_status_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::msg_gen::mainvehicle_status_<ContainerAllocator1> & lhs, const ::msg_gen::mainvehicle_status_<ContainerAllocator2> & rhs)
{
  return lhs.mainVehicleId == rhs.mainVehicleId &&
    lhs.mainVehicleStatus == rhs.mainVehicleStatus;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::msg_gen::mainvehicle_status_<ContainerAllocator1> & lhs, const ::msg_gen::mainvehicle_status_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace msg_gen

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::msg_gen::mainvehicle_status_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msg_gen::mainvehicle_status_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_gen::mainvehicle_status_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_gen::mainvehicle_status_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_gen::mainvehicle_status_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_gen::mainvehicle_status_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::msg_gen::mainvehicle_status_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f1fda3005b741a625447446e183b8fd7";
  }

  static const char* value(const ::msg_gen::mainvehicle_status_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf1fda3005b741a62ULL;
  static const uint64_t static_value2 = 0x5447446e183b8fd7ULL;
};

template<class ContainerAllocator>
struct DataType< ::msg_gen::mainvehicle_status_<ContainerAllocator> >
{
  static const char* value()
  {
    return "msg_gen/mainvehicle_status";
  }

  static const char* value(const ::msg_gen::mainvehicle_status_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::msg_gen::mainvehicle_status_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 mainVehicleId\n"
"int32 mainVehicleStatus\n"
;
  }

  static const char* value(const ::msg_gen::mainvehicle_status_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::msg_gen::mainvehicle_status_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.mainVehicleId);
      stream.next(m.mainVehicleStatus);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct mainvehicle_status_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::msg_gen::mainvehicle_status_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::msg_gen::mainvehicle_status_<ContainerAllocator>& v)
  {
    s << indent << "mainVehicleId: ";
    Printer<int32_t>::stream(s, indent + "  ", v.mainVehicleId);
    s << indent << "mainVehicleStatus: ";
    Printer<int32_t>::stream(s, indent + "  ", v.mainVehicleStatus);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MSG_GEN_MESSAGE_MAINVEHICLE_STATUS_H