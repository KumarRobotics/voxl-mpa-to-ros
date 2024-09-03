// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from voxl_msgs:msg/Aidetection.idl
// generated code does not contain a copyright notice
#include "voxl_msgs/msg/detail/aidetection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `class_name`
// Member `cam`
#include "rosidl_runtime_c/string_functions.h"

bool
voxl_msgs__msg__Aidetection__init(voxl_msgs__msg__Aidetection * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp_ns
  // class_id
  // frame_id
  // class_name
  if (!rosidl_runtime_c__String__init(&msg->class_name)) {
    voxl_msgs__msg__Aidetection__fini(msg);
    return false;
  }
  // cam
  if (!rosidl_runtime_c__String__init(&msg->cam)) {
    voxl_msgs__msg__Aidetection__fini(msg);
    return false;
  }
  // class_confidence
  // detection_confidence
  // x_min
  // y_min
  // x_max
  // y_max
  return true;
}

void
voxl_msgs__msg__Aidetection__fini(voxl_msgs__msg__Aidetection * msg)
{
  if (!msg) {
    return;
  }
  // timestamp_ns
  // class_id
  // frame_id
  // class_name
  rosidl_runtime_c__String__fini(&msg->class_name);
  // cam
  rosidl_runtime_c__String__fini(&msg->cam);
  // class_confidence
  // detection_confidence
  // x_min
  // y_min
  // x_max
  // y_max
}

bool
voxl_msgs__msg__Aidetection__are_equal(const voxl_msgs__msg__Aidetection * lhs, const voxl_msgs__msg__Aidetection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // timestamp_ns
  if (lhs->timestamp_ns != rhs->timestamp_ns) {
    return false;
  }
  // class_id
  if (lhs->class_id != rhs->class_id) {
    return false;
  }
  // frame_id
  if (lhs->frame_id != rhs->frame_id) {
    return false;
  }
  // class_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->class_name), &(rhs->class_name)))
  {
    return false;
  }
  // cam
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->cam), &(rhs->cam)))
  {
    return false;
  }
  // class_confidence
  if (lhs->class_confidence != rhs->class_confidence) {
    return false;
  }
  // detection_confidence
  if (lhs->detection_confidence != rhs->detection_confidence) {
    return false;
  }
  // x_min
  if (lhs->x_min != rhs->x_min) {
    return false;
  }
  // y_min
  if (lhs->y_min != rhs->y_min) {
    return false;
  }
  // x_max
  if (lhs->x_max != rhs->x_max) {
    return false;
  }
  // y_max
  if (lhs->y_max != rhs->y_max) {
    return false;
  }
  return true;
}

bool
voxl_msgs__msg__Aidetection__copy(
  const voxl_msgs__msg__Aidetection * input,
  voxl_msgs__msg__Aidetection * output)
{
  if (!input || !output) {
    return false;
  }
  // timestamp_ns
  output->timestamp_ns = input->timestamp_ns;
  // class_id
  output->class_id = input->class_id;
  // frame_id
  output->frame_id = input->frame_id;
  // class_name
  if (!rosidl_runtime_c__String__copy(
      &(input->class_name), &(output->class_name)))
  {
    return false;
  }
  // cam
  if (!rosidl_runtime_c__String__copy(
      &(input->cam), &(output->cam)))
  {
    return false;
  }
  // class_confidence
  output->class_confidence = input->class_confidence;
  // detection_confidence
  output->detection_confidence = input->detection_confidence;
  // x_min
  output->x_min = input->x_min;
  // y_min
  output->y_min = input->y_min;
  // x_max
  output->x_max = input->x_max;
  // y_max
  output->y_max = input->y_max;
  return true;
}

voxl_msgs__msg__Aidetection *
voxl_msgs__msg__Aidetection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  voxl_msgs__msg__Aidetection * msg = (voxl_msgs__msg__Aidetection *)allocator.allocate(sizeof(voxl_msgs__msg__Aidetection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(voxl_msgs__msg__Aidetection));
  bool success = voxl_msgs__msg__Aidetection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
voxl_msgs__msg__Aidetection__destroy(voxl_msgs__msg__Aidetection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    voxl_msgs__msg__Aidetection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
voxl_msgs__msg__Aidetection__Sequence__init(voxl_msgs__msg__Aidetection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  voxl_msgs__msg__Aidetection * data = NULL;

  if (size) {
    data = (voxl_msgs__msg__Aidetection *)allocator.zero_allocate(size, sizeof(voxl_msgs__msg__Aidetection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = voxl_msgs__msg__Aidetection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        voxl_msgs__msg__Aidetection__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
voxl_msgs__msg__Aidetection__Sequence__fini(voxl_msgs__msg__Aidetection__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      voxl_msgs__msg__Aidetection__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

voxl_msgs__msg__Aidetection__Sequence *
voxl_msgs__msg__Aidetection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  voxl_msgs__msg__Aidetection__Sequence * array = (voxl_msgs__msg__Aidetection__Sequence *)allocator.allocate(sizeof(voxl_msgs__msg__Aidetection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = voxl_msgs__msg__Aidetection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
voxl_msgs__msg__Aidetection__Sequence__destroy(voxl_msgs__msg__Aidetection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    voxl_msgs__msg__Aidetection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
voxl_msgs__msg__Aidetection__Sequence__are_equal(const voxl_msgs__msg__Aidetection__Sequence * lhs, const voxl_msgs__msg__Aidetection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!voxl_msgs__msg__Aidetection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
voxl_msgs__msg__Aidetection__Sequence__copy(
  const voxl_msgs__msg__Aidetection__Sequence * input,
  voxl_msgs__msg__Aidetection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(voxl_msgs__msg__Aidetection);
    voxl_msgs__msg__Aidetection * data =
      (voxl_msgs__msg__Aidetection *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!voxl_msgs__msg__Aidetection__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          voxl_msgs__msg__Aidetection__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!voxl_msgs__msg__Aidetection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
