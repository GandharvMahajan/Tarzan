// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from msgs_srvs:msg/PWMServoStateDuration.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "msgs_srvs/msg/detail/pwm_servo_state_duration__rosidl_typesupport_introspection_c.h"
#include "msgs_srvs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "msgs_srvs/msg/detail/pwm_servo_state_duration__functions.h"
#include "msgs_srvs/msg/detail/pwm_servo_state_duration__struct.h"


// Include directives for member types
// Member `state`
#include "msgs_srvs/msg/pwm_servo_state.h"
// Member `state`
#include "msgs_srvs/msg/detail/pwm_servo_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__PWMServoStateDuration_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  msgs_srvs__msg__PWMServoStateDuration__init(message_memory);
}

void msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__PWMServoStateDuration_fini_function(void * message_memory)
{
  msgs_srvs__msg__PWMServoStateDuration__fini(message_memory);
}

size_t msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__size_function__PWMServoStateDuration__state(
  const void * untyped_member)
{
  const msgs_srvs__msg__PWMServoState__Sequence * member =
    (const msgs_srvs__msg__PWMServoState__Sequence *)(untyped_member);
  return member->size;
}

const void * msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__get_const_function__PWMServoStateDuration__state(
  const void * untyped_member, size_t index)
{
  const msgs_srvs__msg__PWMServoState__Sequence * member =
    (const msgs_srvs__msg__PWMServoState__Sequence *)(untyped_member);
  return &member->data[index];
}

void * msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__get_function__PWMServoStateDuration__state(
  void * untyped_member, size_t index)
{
  msgs_srvs__msg__PWMServoState__Sequence * member =
    (msgs_srvs__msg__PWMServoState__Sequence *)(untyped_member);
  return &member->data[index];
}

void msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__fetch_function__PWMServoStateDuration__state(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const msgs_srvs__msg__PWMServoState * item =
    ((const msgs_srvs__msg__PWMServoState *)
    msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__get_const_function__PWMServoStateDuration__state(untyped_member, index));
  msgs_srvs__msg__PWMServoState * value =
    (msgs_srvs__msg__PWMServoState *)(untyped_value);
  *value = *item;
}

void msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__assign_function__PWMServoStateDuration__state(
  void * untyped_member, size_t index, const void * untyped_value)
{
  msgs_srvs__msg__PWMServoState * item =
    ((msgs_srvs__msg__PWMServoState *)
    msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__get_function__PWMServoStateDuration__state(untyped_member, index));
  const msgs_srvs__msg__PWMServoState * value =
    (const msgs_srvs__msg__PWMServoState *)(untyped_value);
  *item = *value;
}

bool msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__resize_function__PWMServoStateDuration__state(
  void * untyped_member, size_t size)
{
  msgs_srvs__msg__PWMServoState__Sequence * member =
    (msgs_srvs__msg__PWMServoState__Sequence *)(untyped_member);
  msgs_srvs__msg__PWMServoState__Sequence__fini(member);
  return msgs_srvs__msg__PWMServoState__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__PWMServoStateDuration_message_member_array[2] = {
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs_srvs__msg__PWMServoStateDuration, state),  // bytes offset in struct
    NULL,  // default value
    msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__size_function__PWMServoStateDuration__state,  // size() function pointer
    msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__get_const_function__PWMServoStateDuration__state,  // get_const(index) function pointer
    msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__get_function__PWMServoStateDuration__state,  // get(index) function pointer
    msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__fetch_function__PWMServoStateDuration__state,  // fetch(index, &value) function pointer
    msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__assign_function__PWMServoStateDuration__state,  // assign(index, value) function pointer
    msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__resize_function__PWMServoStateDuration__state  // resize(index) function pointer
  },
  {
    "duration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs_srvs__msg__PWMServoStateDuration, duration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__PWMServoStateDuration_message_members = {
  "msgs_srvs__msg",  // message namespace
  "PWMServoStateDuration",  // message name
  2,  // number of fields
  sizeof(msgs_srvs__msg__PWMServoStateDuration),
  msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__PWMServoStateDuration_message_member_array,  // message members
  msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__PWMServoStateDuration_init_function,  // function to initialize message memory (memory has to be allocated)
  msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__PWMServoStateDuration_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__PWMServoStateDuration_message_type_support_handle = {
  0,
  &msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__PWMServoStateDuration_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_msgs_srvs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs_srvs, msg, PWMServoStateDuration)() {
  msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__PWMServoStateDuration_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs_srvs, msg, PWMServoState)();
  if (!msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__PWMServoStateDuration_message_type_support_handle.typesupport_identifier) {
    msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__PWMServoStateDuration_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &msgs_srvs__msg__PWMServoStateDuration__rosidl_typesupport_introspection_c__PWMServoStateDuration_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
