// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from voxl_msgs:msg/Aidetection.idl
// generated code does not contain a copyright notice

#ifndef VOXL_MSGS__MSG__DETAIL__AIDETECTION__STRUCT_H_
#define VOXL_MSGS__MSG__DETAIL__AIDETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'class_name'
// Member 'cam'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/Aidetection in the package voxl_msgs.
typedef struct voxl_msgs__msg__Aidetection
{
  int64_t timestamp_ns;
  uint32_t class_id;
  uint32_t frame_id;
  rosidl_runtime_c__String class_name;
  rosidl_runtime_c__String cam;
  float class_confidence;
  float detection_confidence;
  float x_min;
  float y_min;
  float x_max;
  float y_max;
} voxl_msgs__msg__Aidetection;

// Struct for a sequence of voxl_msgs__msg__Aidetection.
typedef struct voxl_msgs__msg__Aidetection__Sequence
{
  voxl_msgs__msg__Aidetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} voxl_msgs__msg__Aidetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VOXL_MSGS__MSG__DETAIL__AIDETECTION__STRUCT_H_
