// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs_srvs:msg/BuzzerState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__BUZZER_STATE__STRUCT_H_
#define MSGS_SRVS__MSG__DETAIL__BUZZER_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/BuzzerState in the package msgs_srvs.
typedef struct msgs_srvs__msg__BuzzerState
{
  uint16_t freq;
  float on_time;
  float off_time;
  uint16_t repeat;
} msgs_srvs__msg__BuzzerState;

// Struct for a sequence of msgs_srvs__msg__BuzzerState.
typedef struct msgs_srvs__msg__BuzzerState__Sequence
{
  msgs_srvs__msg__BuzzerState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs_srvs__msg__BuzzerState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS_SRVS__MSG__DETAIL__BUZZER_STATE__STRUCT_H_
