// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs_srvs:msg/PWMServoState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE__STRUCT_H_
#define MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/PWMServoState in the package msgs_srvs.
typedef struct msgs_srvs__msg__PWMServoState
{
  uint8_t id;
  uint8_t position;
  uint8_t offset;
} msgs_srvs__msg__PWMServoState;

// Struct for a sequence of msgs_srvs__msg__PWMServoState.
typedef struct msgs_srvs__msg__PWMServoState__Sequence
{
  msgs_srvs__msg__PWMServoState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs_srvs__msg__PWMServoState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE__STRUCT_H_
