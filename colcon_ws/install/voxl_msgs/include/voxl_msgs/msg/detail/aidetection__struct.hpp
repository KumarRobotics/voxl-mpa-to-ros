// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from voxl_msgs:msg/Aidetection.idl
// generated code does not contain a copyright notice

#ifndef VOXL_MSGS__MSG__DETAIL__AIDETECTION__STRUCT_HPP_
#define VOXL_MSGS__MSG__DETAIL__AIDETECTION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__voxl_msgs__msg__Aidetection __attribute__((deprecated))
#else
# define DEPRECATED__voxl_msgs__msg__Aidetection __declspec(deprecated)
#endif

namespace voxl_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Aidetection_
{
  using Type = Aidetection_<ContainerAllocator>;

  explicit Aidetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp_ns = 0ll;
      this->class_id = 0ul;
      this->frame_id = 0ul;
      this->class_name = "";
      this->cam = "";
      this->class_confidence = 0.0f;
      this->detection_confidence = 0.0f;
      this->x_min = 0.0f;
      this->y_min = 0.0f;
      this->x_max = 0.0f;
      this->y_max = 0.0f;
    }
  }

  explicit Aidetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : class_name(_alloc),
    cam(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp_ns = 0ll;
      this->class_id = 0ul;
      this->frame_id = 0ul;
      this->class_name = "";
      this->cam = "";
      this->class_confidence = 0.0f;
      this->detection_confidence = 0.0f;
      this->x_min = 0.0f;
      this->y_min = 0.0f;
      this->x_max = 0.0f;
      this->y_max = 0.0f;
    }
  }

  // field types and members
  using _timestamp_ns_type =
    int64_t;
  _timestamp_ns_type timestamp_ns;
  using _class_id_type =
    uint32_t;
  _class_id_type class_id;
  using _frame_id_type =
    uint32_t;
  _frame_id_type frame_id;
  using _class_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _class_name_type class_name;
  using _cam_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _cam_type cam;
  using _class_confidence_type =
    float;
  _class_confidence_type class_confidence;
  using _detection_confidence_type =
    float;
  _detection_confidence_type detection_confidence;
  using _x_min_type =
    float;
  _x_min_type x_min;
  using _y_min_type =
    float;
  _y_min_type y_min;
  using _x_max_type =
    float;
  _x_max_type x_max;
  using _y_max_type =
    float;
  _y_max_type y_max;

  // setters for named parameter idiom
  Type & set__timestamp_ns(
    const int64_t & _arg)
  {
    this->timestamp_ns = _arg;
    return *this;
  }
  Type & set__class_id(
    const uint32_t & _arg)
  {
    this->class_id = _arg;
    return *this;
  }
  Type & set__frame_id(
    const uint32_t & _arg)
  {
    this->frame_id = _arg;
    return *this;
  }
  Type & set__class_name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->class_name = _arg;
    return *this;
  }
  Type & set__cam(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->cam = _arg;
    return *this;
  }
  Type & set__class_confidence(
    const float & _arg)
  {
    this->class_confidence = _arg;
    return *this;
  }
  Type & set__detection_confidence(
    const float & _arg)
  {
    this->detection_confidence = _arg;
    return *this;
  }
  Type & set__x_min(
    const float & _arg)
  {
    this->x_min = _arg;
    return *this;
  }
  Type & set__y_min(
    const float & _arg)
  {
    this->y_min = _arg;
    return *this;
  }
  Type & set__x_max(
    const float & _arg)
  {
    this->x_max = _arg;
    return *this;
  }
  Type & set__y_max(
    const float & _arg)
  {
    this->y_max = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    voxl_msgs::msg::Aidetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const voxl_msgs::msg::Aidetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<voxl_msgs::msg::Aidetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<voxl_msgs::msg::Aidetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      voxl_msgs::msg::Aidetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<voxl_msgs::msg::Aidetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      voxl_msgs::msg::Aidetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<voxl_msgs::msg::Aidetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<voxl_msgs::msg::Aidetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<voxl_msgs::msg::Aidetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__voxl_msgs__msg__Aidetection
    std::shared_ptr<voxl_msgs::msg::Aidetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__voxl_msgs__msg__Aidetection
    std::shared_ptr<voxl_msgs::msg::Aidetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Aidetection_ & other) const
  {
    if (this->timestamp_ns != other.timestamp_ns) {
      return false;
    }
    if (this->class_id != other.class_id) {
      return false;
    }
    if (this->frame_id != other.frame_id) {
      return false;
    }
    if (this->class_name != other.class_name) {
      return false;
    }
    if (this->cam != other.cam) {
      return false;
    }
    if (this->class_confidence != other.class_confidence) {
      return false;
    }
    if (this->detection_confidence != other.detection_confidence) {
      return false;
    }
    if (this->x_min != other.x_min) {
      return false;
    }
    if (this->y_min != other.y_min) {
      return false;
    }
    if (this->x_max != other.x_max) {
      return false;
    }
    if (this->y_max != other.y_max) {
      return false;
    }
    return true;
  }
  bool operator!=(const Aidetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Aidetection_

// alias to use template instance with default allocator
using Aidetection =
  voxl_msgs::msg::Aidetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace voxl_msgs

#endif  // VOXL_MSGS__MSG__DETAIL__AIDETECTION__STRUCT_HPP_
