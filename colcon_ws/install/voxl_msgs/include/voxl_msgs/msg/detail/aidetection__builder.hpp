// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from voxl_msgs:msg/Aidetection.idl
// generated code does not contain a copyright notice

#ifndef VOXL_MSGS__MSG__DETAIL__AIDETECTION__BUILDER_HPP_
#define VOXL_MSGS__MSG__DETAIL__AIDETECTION__BUILDER_HPP_

#include "voxl_msgs/msg/detail/aidetection__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace voxl_msgs
{

namespace msg
{

namespace builder
{

class Init_Aidetection_y_max
{
public:
  explicit Init_Aidetection_y_max(::voxl_msgs::msg::Aidetection & msg)
  : msg_(msg)
  {}
  ::voxl_msgs::msg::Aidetection y_max(::voxl_msgs::msg::Aidetection::_y_max_type arg)
  {
    msg_.y_max = std::move(arg);
    return std::move(msg_);
  }

private:
  ::voxl_msgs::msg::Aidetection msg_;
};

class Init_Aidetection_x_max
{
public:
  explicit Init_Aidetection_x_max(::voxl_msgs::msg::Aidetection & msg)
  : msg_(msg)
  {}
  Init_Aidetection_y_max x_max(::voxl_msgs::msg::Aidetection::_x_max_type arg)
  {
    msg_.x_max = std::move(arg);
    return Init_Aidetection_y_max(msg_);
  }

private:
  ::voxl_msgs::msg::Aidetection msg_;
};

class Init_Aidetection_y_min
{
public:
  explicit Init_Aidetection_y_min(::voxl_msgs::msg::Aidetection & msg)
  : msg_(msg)
  {}
  Init_Aidetection_x_max y_min(::voxl_msgs::msg::Aidetection::_y_min_type arg)
  {
    msg_.y_min = std::move(arg);
    return Init_Aidetection_x_max(msg_);
  }

private:
  ::voxl_msgs::msg::Aidetection msg_;
};

class Init_Aidetection_x_min
{
public:
  explicit Init_Aidetection_x_min(::voxl_msgs::msg::Aidetection & msg)
  : msg_(msg)
  {}
  Init_Aidetection_y_min x_min(::voxl_msgs::msg::Aidetection::_x_min_type arg)
  {
    msg_.x_min = std::move(arg);
    return Init_Aidetection_y_min(msg_);
  }

private:
  ::voxl_msgs::msg::Aidetection msg_;
};

class Init_Aidetection_detection_confidence
{
public:
  explicit Init_Aidetection_detection_confidence(::voxl_msgs::msg::Aidetection & msg)
  : msg_(msg)
  {}
  Init_Aidetection_x_min detection_confidence(::voxl_msgs::msg::Aidetection::_detection_confidence_type arg)
  {
    msg_.detection_confidence = std::move(arg);
    return Init_Aidetection_x_min(msg_);
  }

private:
  ::voxl_msgs::msg::Aidetection msg_;
};

class Init_Aidetection_class_confidence
{
public:
  explicit Init_Aidetection_class_confidence(::voxl_msgs::msg::Aidetection & msg)
  : msg_(msg)
  {}
  Init_Aidetection_detection_confidence class_confidence(::voxl_msgs::msg::Aidetection::_class_confidence_type arg)
  {
    msg_.class_confidence = std::move(arg);
    return Init_Aidetection_detection_confidence(msg_);
  }

private:
  ::voxl_msgs::msg::Aidetection msg_;
};

class Init_Aidetection_cam
{
public:
  explicit Init_Aidetection_cam(::voxl_msgs::msg::Aidetection & msg)
  : msg_(msg)
  {}
  Init_Aidetection_class_confidence cam(::voxl_msgs::msg::Aidetection::_cam_type arg)
  {
    msg_.cam = std::move(arg);
    return Init_Aidetection_class_confidence(msg_);
  }

private:
  ::voxl_msgs::msg::Aidetection msg_;
};

class Init_Aidetection_class_name
{
public:
  explicit Init_Aidetection_class_name(::voxl_msgs::msg::Aidetection & msg)
  : msg_(msg)
  {}
  Init_Aidetection_cam class_name(::voxl_msgs::msg::Aidetection::_class_name_type arg)
  {
    msg_.class_name = std::move(arg);
    return Init_Aidetection_cam(msg_);
  }

private:
  ::voxl_msgs::msg::Aidetection msg_;
};

class Init_Aidetection_frame_id
{
public:
  explicit Init_Aidetection_frame_id(::voxl_msgs::msg::Aidetection & msg)
  : msg_(msg)
  {}
  Init_Aidetection_class_name frame_id(::voxl_msgs::msg::Aidetection::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return Init_Aidetection_class_name(msg_);
  }

private:
  ::voxl_msgs::msg::Aidetection msg_;
};

class Init_Aidetection_class_id
{
public:
  explicit Init_Aidetection_class_id(::voxl_msgs::msg::Aidetection & msg)
  : msg_(msg)
  {}
  Init_Aidetection_frame_id class_id(::voxl_msgs::msg::Aidetection::_class_id_type arg)
  {
    msg_.class_id = std::move(arg);
    return Init_Aidetection_frame_id(msg_);
  }

private:
  ::voxl_msgs::msg::Aidetection msg_;
};

class Init_Aidetection_timestamp_ns
{
public:
  Init_Aidetection_timestamp_ns()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Aidetection_class_id timestamp_ns(::voxl_msgs::msg::Aidetection::_timestamp_ns_type arg)
  {
    msg_.timestamp_ns = std::move(arg);
    return Init_Aidetection_class_id(msg_);
  }

private:
  ::voxl_msgs::msg::Aidetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::voxl_msgs::msg::Aidetection>()
{
  return voxl_msgs::msg::builder::Init_Aidetection_timestamp_ns();
}

}  // namespace voxl_msgs

#endif  // VOXL_MSGS__MSG__DETAIL__AIDETECTION__BUILDER_HPP_
