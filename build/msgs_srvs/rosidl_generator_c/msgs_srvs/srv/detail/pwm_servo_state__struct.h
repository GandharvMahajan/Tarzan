// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msgs_srvs:srv/PWMServoState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__SRV__DETAIL__PWM_SERVO_STATE__STRUCT_H_
#define MSGS_SRVS__SRV__DETAIL__PWM_SERVO_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'cmd'
#include "msgs_srvs/msg/detail/pwm_servo_state__struct.h"

/// Struct defined in srv/PWMServoState in the package msgs_srvs.
typedef struct msgs_srvs__srv__PWMServoState_Request
{
  msgs_srvs__msg__PWMServoState__Sequence cmd;
} msgs_srvs__srv__PWMServoState_Request;

// Struct for a sequence of msgs_srvs__srv__PWMServoState_Request.
typedef struct msgs_srvs__srv__PWMServoState_Request__Sequence
{
  msgs_srvs__srv__PWMServoState_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs_srvs__srv__PWMServoState_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'state'
// already included above
// #include "msgs_srvs/msg/detail/pwm_servo_state__struct.h"

/// Struct defined in srv/PWMServoState in the package msgs_srvs.
typedef struct msgs_srvs__srv__PWMServoState_Response
{
  bool success;
  msgs_srvs__msg__PWMServoState__Sequence state;
} msgs_srvs__srv__PWMServoState_Response;

// Struct for a sequence of msgs_srvs__srv__PWMServoState_Response.
typedef struct msgs_srvs__srv__PWMServoState_Response__Sequence
{
  msgs_srvs__srv__PWMServoState_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msgs_srvs__srv__PWMServoState_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSGS_SRVS__SRV__DETAIL__PWM_SERVO_STATE__STRUCT_H_
