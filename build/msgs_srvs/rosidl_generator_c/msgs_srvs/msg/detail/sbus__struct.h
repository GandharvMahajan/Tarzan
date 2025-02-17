// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs_srvs:msg/Sbus.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__SBUS__STRUCT_H_
#define MSGS_SRVS__MSG__DETAIL__SBUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'channel'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Sbus in the package msgs_srvs.
typedef struct msgs_srvs__msg__Sbus
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__float__Sequence channel;
} msgs_srvs__msg__Sbus;

// Struct for a sequence of msgs_srvs__msg__Sbus.
typedef struct msgs_srvs__msg__Sbus__Sequence
{
  msgs_srvs__msg__Sbus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs_srvs__msg__Sbus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS_SRVS__MSG__DETAIL__SBUS__STRUCT_H_
