// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from msgs_srvs:msg/PWMServoState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "msgs_srvs/msg/detail/pwm_servo_state__rosidl_typesupport_introspection_c.h"
#include "msgs_srvs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "msgs_srvs/msg/detail/pwm_servo_state__functions.h"
#include "msgs_srvs/msg/detail/pwm_servo_state__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void msgs_srvs__msg__PWMServoState__rosidl_typesupport_introspection_c__PWMServoState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  msgs_srvs__msg__PWMServoState__init(message_memory);
}

void msgs_srvs__msg__PWMServoState__rosidl_typesupport_introspection_c__PWMServoState_fini_function(void * message_memory)
{
  msgs_srvs__msg__PWMServoState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember msgs_srvs__msg__PWMServoState__rosidl_typesupport_introspection_c__PWMServoState_message_member_array[3] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs_srvs__msg__PWMServoState, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs_srvs__msg__PWMServoState, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "offset",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs_srvs__msg__PWMServoState, offset),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers msgs_srvs__msg__PWMServoState__rosidl_typesupport_introspection_c__PWMServoState_message_members = {
  "msgs_srvs__msg",  // message namespace
  "PWMServoState",  // message name
  3,  // number of fields
  sizeof(msgs_srvs__msg__PWMServoState),
  msgs_srvs__msg__PWMServoState__rosidl_typesupport_introspection_c__PWMServoState_message_member_array,  // message members
  msgs_srvs__msg__PWMServoState__rosidl_typesupport_introspection_c__PWMServoState_init_function,  // function to initialize message memory (memory has to be allocated)
  msgs_srvs__msg__PWMServoState__rosidl_typesupport_introspection_c__PWMServoState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t msgs_srvs__msg__PWMServoState__rosidl_typesupport_introspection_c__PWMServoState_message_type_support_handle = {
  0,
  &msgs_srvs__msg__PWMServoState__rosidl_typesupport_introspection_c__PWMServoState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_msgs_srvs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs_srvs, msg, PWMServoState)() {
  if (!msgs_srvs__msg__PWMServoState__rosidl_typesupport_introspection_c__PWMServoState_message_type_support_handle.typesupport_identifier) {
    msgs_srvs__msg__PWMServoState__rosidl_typesupport_introspection_c__PWMServoState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &msgs_srvs__msg__PWMServoState__rosidl_typesupport_introspection_c__PWMServoState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
