// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from voxl_msgs:msg/Aidetection.idl
// generated code does not contain a copyright notice

#ifndef VOXL_MSGS__MSG__DETAIL__AIDETECTION__TRAITS_HPP_
#define VOXL_MSGS__MSG__DETAIL__AIDETECTION__TRAITS_HPP_

#include "voxl_msgs/msg/detail/aidetection__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<voxl_msgs::msg::Aidetection>()
{
  return "voxl_msgs::msg::Aidetection";
}

template<>
inline const char * name<voxl_msgs::msg::Aidetection>()
{
  return "voxl_msgs/msg/Aidetection";
}

template<>
struct has_fixed_size<voxl_msgs::msg::Aidetection>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<voxl_msgs::msg::Aidetection>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<voxl_msgs::msg::Aidetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VOXL_MSGS__MSG__DETAIL__AIDETECTION__TRAITS_HPP_
