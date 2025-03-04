// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs_srvs:msg/MotorsState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__MOTORS_STATE__STRUCT_H_
#define MSGS_SRVS__MSG__DETAIL__MOTORS_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "msgs_srvs/msg/detail/motor_state__struct.h"

/// Struct defined in msg/MotorsState in the package msgs_srvs.
typedef struct msgs_srvs__msg__MotorsState
{
  msgs_srvs__msg__MotorState__Sequence data;
} msgs_srvs__msg__MotorsState;

// Struct for a sequence of msgs_srvs__msg__MotorsState.
typedef struct msgs_srvs__msg__MotorsState__Sequence
{
  msgs_srvs__msg__MotorsState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs_srvs__msg__MotorsState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS_SRVS__MSG__DETAIL__MOTORS_STATE__STRUCT_H_
