// Generated by gencpp from file msg_gen/SimOne_Data_Position_Info_Array.msg
// DO NOT EDIT!


#ifndef MSG_GEN_MESSAGE_SIMONE_DATA_POSITION_INFO_ARRAY_H
#define MSG_GEN_MESSAGE_SIMONE_DATA_POSITION_INFO_ARRAY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <msg_gen/SimOne_Data_Position_Info.h>
#include <msg_gen/SimOne_Data_Position_Info.h>

namespace msg_gen
{
template <class ContainerAllocator>
struct SimOne_Data_Position_Info_Array_
{
  typedef SimOne_Data_Position_Info_Array_<ContainerAllocator> Type;

  SimOne_Data_Position_Info_Array_()
    : ped_prediction()
    , veh_prediction()  {
    }
  SimOne_Data_Position_Info_Array_(const ContainerAllocator& _alloc)
    : ped_prediction(_alloc)
    , veh_prediction(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::msg_gen::SimOne_Data_Position_Info_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::msg_gen::SimOne_Data_Position_Info_<ContainerAllocator> >::other >  _ped_prediction_type;
  _ped_prediction_type ped_prediction;

   typedef std::vector< ::msg_gen::SimOne_Data_Position_Info_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::msg_gen::SimOne_Data_Position_Info_<ContainerAllocator> >::other >  _veh_prediction_type;
  _veh_prediction_type veh_prediction;





  typedef boost::shared_ptr< ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator> const> ConstPtr;

}; // struct SimOne_Data_Position_Info_Array_

typedef ::msg_gen::SimOne_Data_Position_Info_Array_<std::allocator<void> > SimOne_Data_Position_Info_Array;

typedef boost::shared_ptr< ::msg_gen::SimOne_Data_Position_Info_Array > SimOne_Data_Position_Info_ArrayPtr;
typedef boost::shared_ptr< ::msg_gen::SimOne_Data_Position_Info_Array const> SimOne_Data_Position_Info_ArrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator1> & lhs, const ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator2> & rhs)
{
  return lhs.ped_prediction == rhs.ped_prediction &&
    lhs.veh_prediction == rhs.veh_prediction;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator1> & lhs, const ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace msg_gen

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator> >
{
  static const char* value()
  {
    return "28eb851ff6cf0a1e4154e2a07e7400c8";
  }

  static const char* value(const ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x28eb851ff6cf0a1eULL;
  static const uint64_t static_value2 = 0x4154e2a07e7400c8ULL;
};

template<class ContainerAllocator>
struct DataType< ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator> >
{
  static const char* value()
  {
    return "msg_gen/SimOne_Data_Position_Info_Array";
  }

  static const char* value(const ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator> >
{
  static const char* value()
  {
    return "SimOne_Data_Position_Info[] ped_prediction\n"
"SimOne_Data_Position_Info[] veh_prediction\n"
"================================================================================\n"
"MSG: msg_gen/SimOne_Data_Position_Info\n"
"float64 mean_x\n"
"float64 mean_y\n"
"float64 var_x\n"
"float64 var_y\n"
"float64 covar_xy\n"
;
  }

  static const char* value(const ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ped_prediction);
      stream.next(m.veh_prediction);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SimOne_Data_Position_Info_Array_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::msg_gen::SimOne_Data_Position_Info_Array_<ContainerAllocator>& v)
  {
    s << indent << "ped_prediction[]" << std::endl;
    for (size_t i = 0; i < v.ped_prediction.size(); ++i)
    {
      s << indent << "  ped_prediction[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::msg_gen::SimOne_Data_Position_Info_<ContainerAllocator> >::stream(s, indent + "    ", v.ped_prediction[i]);
    }
    s << indent << "veh_prediction[]" << std::endl;
    for (size_t i = 0; i < v.veh_prediction.size(); ++i)
    {
      s << indent << "  veh_prediction[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::msg_gen::SimOne_Data_Position_Info_<ContainerAllocator> >::stream(s, indent + "    ", v.veh_prediction[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // MSG_GEN_MESSAGE_SIMONE_DATA_POSITION_INFO_ARRAY_H
