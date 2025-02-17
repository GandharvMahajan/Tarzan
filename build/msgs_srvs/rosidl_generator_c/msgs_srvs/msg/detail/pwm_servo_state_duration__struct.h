// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs_srvs:msg/PWMServoStateDuration.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE_DURATION__STRUCT_H_
#define MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE_DURATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'state'
#include "msgs_srvs/msg/detail/pwm_servo_state__struct.h"

/// Struct defined in msg/PWMServoStateDuration in the package msgs_srvs.
typedef struct msgs_srvs__msg__PWMServoStateDuration
{
  msgs_srvs__msg__PWMServoState__Sequence state;
  double duration;
} msgs_srvs__msg__PWMServoStateDuration;

// Struct for a sequence of msgs_srvs__msg__PWMServoStateDuration.
typedef struct msgs_srvs__msg__PWMServoStateDuration__Sequence
{
  msgs_srvs__msg__PWMServoStateDuration * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs_srvs__msg__PWMServoStateDuration__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE_DURATION__STRUCT_H_
