// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs_srvs:msg/ButtonState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__BUTTON_STATE__STRUCT_H_
#define MSGS_SRVS__MSG__DETAIL__BUTTON_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ButtonState in the package msgs_srvs.
typedef struct msgs_srvs__msg__ButtonState
{
  uint8_t id;
  uint8_t state;
} msgs_srvs__msg__ButtonState;

// Struct for a sequence of msgs_srvs__msg__ButtonState.
typedef struct msgs_srvs__msg__ButtonState__Sequence
{
  msgs_srvs__msg__ButtonState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs_srvs__msg__ButtonState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS_SRVS__MSG__DETAIL__BUTTON_STATE__STRUCT_H_
