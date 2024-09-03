// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from voxl_msgs:msg/Aidetection.idl
// generated code does not contain a copyright notice

#ifndef VOXL_MSGS__MSG__DETAIL__AIDETECTION__FUNCTIONS_H_
#define VOXL_MSGS__MSG__DETAIL__AIDETECTION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "voxl_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "voxl_msgs/msg/detail/aidetection__struct.h"

/// Initialize msg/Aidetection message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * voxl_msgs__msg__Aidetection
 * )) before or use
 * voxl_msgs__msg__Aidetection__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_voxl_msgs
bool
voxl_msgs__msg__Aidetection__init(voxl_msgs__msg__Aidetection * msg);

/// Finalize msg/Aidetection message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_voxl_msgs
void
voxl_msgs__msg__Aidetection__fini(voxl_msgs__msg__Aidetection * msg);

/// Create msg/Aidetection message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * voxl_msgs__msg__Aidetection__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_voxl_msgs
voxl_msgs__msg__Aidetection *
voxl_msgs__msg__Aidetection__create();

/// Destroy msg/Aidetection message.
/**
 * It calls
 * voxl_msgs__msg__Aidetection__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_voxl_msgs
void
voxl_msgs__msg__Aidetection__destroy(voxl_msgs__msg__Aidetection * msg);

/// Check for msg/Aidetection message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_voxl_msgs
bool
voxl_msgs__msg__Aidetection__are_equal(const voxl_msgs__msg__Aidetection * lhs, const voxl_msgs__msg__Aidetection * rhs);

/// Copy a msg/Aidetection message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_voxl_msgs
bool
voxl_msgs__msg__Aidetection__copy(
  const voxl_msgs__msg__Aidetection * input,
  voxl_msgs__msg__Aidetection * output);

/// Initialize array of msg/Aidetection messages.
/**
 * It allocates the memory for the number of elements and calls
 * voxl_msgs__msg__Aidetection__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_voxl_msgs
bool
voxl_msgs__msg__Aidetection__Sequence__init(voxl_msgs__msg__Aidetection__Sequence * array, size_t size);

/// Finalize array of msg/Aidetection messages.
/**
 * It calls
 * voxl_msgs__msg__Aidetection__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_voxl_msgs
void
voxl_msgs__msg__Aidetection__Sequence__fini(voxl_msgs__msg__Aidetection__Sequence * array);

/// Create array of msg/Aidetection messages.
/**
 * It allocates the memory for the array and calls
 * voxl_msgs__msg__Aidetection__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_voxl_msgs
voxl_msgs__msg__Aidetection__Sequence *
voxl_msgs__msg__Aidetection__Sequence__create(size_t size);

/// Destroy array of msg/Aidetection messages.
/**
 * It calls
 * voxl_msgs__msg__Aidetection__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_voxl_msgs
void
voxl_msgs__msg__Aidetection__Sequence__destroy(voxl_msgs__msg__Aidetection__Sequence * array);

/// Check for msg/Aidetection message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_voxl_msgs
bool
voxl_msgs__msg__Aidetection__Sequence__are_equal(const voxl_msgs__msg__Aidetection__Sequence * lhs, const voxl_msgs__msg__Aidetection__Sequence * rhs);

/// Copy an array of msg/Aidetection messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_voxl_msgs
bool
voxl_msgs__msg__Aidetection__Sequence__copy(
  const voxl_msgs__msg__Aidetection__Sequence * input,
  voxl_msgs__msg__Aidetection__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VOXL_MSGS__MSG__DETAIL__AIDETECTION__FUNCTIONS_H_
