// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs_srvs:msg/LedState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__LED_STATE__STRUCT_H_
#define MSGS_SRVS__MSG__DETAIL__LED_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/LedState in the package msgs_srvs.
typedef struct msgs_srvs__msg__LedState
{
  uint8_t id;
  float on_time;
  float off_time;
  uint16_t repeat;
} msgs_srvs__msg__LedState;

// Struct for a sequence of msgs_srvs__msg__LedState.
typedef struct msgs_srvs__msg__LedState__Sequence
{
  msgs_srvs__msg__LedState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs_srvs__msg__LedState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS_SRVS__MSG__DETAIL__LED_STATE__STRUCT_H_
