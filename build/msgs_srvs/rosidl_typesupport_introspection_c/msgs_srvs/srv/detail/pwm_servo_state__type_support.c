// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from msgs_srvs:srv/PWMServoState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "msgs_srvs/srv/detail/pwm_servo_state__rosidl_typesupport_introspection_c.h"
#include "msgs_srvs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "msgs_srvs/srv/detail/pwm_servo_state__functions.h"
#include "msgs_srvs/srv/detail/pwm_servo_state__struct.h"


// Include directives for member types
// Member `cmd`
#include "msgs_srvs/msg/pwm_servo_state.h"
// Member `cmd`
#include "msgs_srvs/msg/detail/pwm_servo_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__PWMServoState_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  msgs_srvs__srv__PWMServoState_Request__init(message_memory);
}

void msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__PWMServoState_Request_fini_function(void * message_memory)
{
  msgs_srvs__srv__PWMServoState_Request__fini(message_memory);
}

size_t msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__size_function__PWMServoState_Request__cmd(
  const void * untyped_member)
{
  const msgs_srvs__msg__PWMServoState__Sequence * member =
    (const msgs_srvs__msg__PWMServoState__Sequence *)(untyped_member);
  return member->size;
}

const void * msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__get_const_function__PWMServoState_Request__cmd(
  const void * untyped_member, size_t index)
{
  const msgs_srvs__msg__PWMServoState__Sequence * member =
    (const msgs_srvs__msg__PWMServoState__Sequence *)(untyped_member);
  return &member->data[index];
}

void * msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__get_function__PWMServoState_Request__cmd(
  void * untyped_member, size_t index)
{
  msgs_srvs__msg__PWMServoState__Sequence * member =
    (msgs_srvs__msg__PWMServoState__Sequence *)(untyped_member);
  return &member->data[index];
}

void msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__fetch_function__PWMServoState_Request__cmd(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const msgs_srvs__msg__PWMServoState * item =
    ((const msgs_srvs__msg__PWMServoState *)
    msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__get_const_function__PWMServoState_Request__cmd(untyped_member, index));
  msgs_srvs__msg__PWMServoState * value =
    (msgs_srvs__msg__PWMServoState *)(untyped_value);
  *value = *item;
}

void msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__assign_function__PWMServoState_Request__cmd(
  void * untyped_member, size_t index, const void * untyped_value)
{
  msgs_srvs__msg__PWMServoState * item =
    ((msgs_srvs__msg__PWMServoState *)
    msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__get_function__PWMServoState_Request__cmd(untyped_member, index));
  const msgs_srvs__msg__PWMServoState * value =
    (const msgs_srvs__msg__PWMServoState *)(untyped_value);
  *item = *value;
}

bool msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__resize_function__PWMServoState_Request__cmd(
  void * untyped_member, size_t size)
{
  msgs_srvs__msg__PWMServoState__Sequence * member =
    (msgs_srvs__msg__PWMServoState__Sequence *)(untyped_member);
  msgs_srvs__msg__PWMServoState__Sequence__fini(member);
  return msgs_srvs__msg__PWMServoState__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__PWMServoState_Request_message_member_array[1] = {
  {
    "cmd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs_srvs__srv__PWMServoState_Request, cmd),  // bytes offset in struct
    NULL,  // default value
    msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__size_function__PWMServoState_Request__cmd,  // size() function pointer
    msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__get_const_function__PWMServoState_Request__cmd,  // get_const(index) function pointer
    msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__get_function__PWMServoState_Request__cmd,  // get(index) function pointer
    msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__fetch_function__PWMServoState_Request__cmd,  // fetch(index, &value) function pointer
    msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__assign_function__PWMServoState_Request__cmd,  // assign(index, value) function pointer
    msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__resize_function__PWMServoState_Request__cmd  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__PWMServoState_Request_message_members = {
  "msgs_srvs__srv",  // message namespace
  "PWMServoState_Request",  // message name
  1,  // number of fields
  sizeof(msgs_srvs__srv__PWMServoState_Request),
  msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__PWMServoState_Request_message_member_array,  // message members
  msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__PWMServoState_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__PWMServoState_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__PWMServoState_Request_message_type_support_handle = {
  0,
  &msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__PWMServoState_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_msgs_srvs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs_srvs, srv, PWMServoState_Request)() {
  msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__PWMServoState_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs_srvs, msg, PWMServoState)();
  if (!msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__PWMServoState_Request_message_type_support_handle.typesupport_identifier) {
    msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__PWMServoState_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &msgs_srvs__srv__PWMServoState_Request__rosidl_typesupport_introspection_c__PWMServoState_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "msgs_srvs/srv/detail/pwm_servo_state__rosidl_typesupport_introspection_c.h"
// already included above
// #include "msgs_srvs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "msgs_srvs/srv/detail/pwm_servo_state__functions.h"
// already included above
// #include "msgs_srvs/srv/detail/pwm_servo_state__struct.h"


// Include directives for member types
// Member `state`
// already included above
// #include "msgs_srvs/msg/pwm_servo_state.h"
// Member `state`
// already included above
// #include "msgs_srvs/msg/detail/pwm_servo_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__PWMServoState_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  msgs_srvs__srv__PWMServoState_Response__init(message_memory);
}

void msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__PWMServoState_Response_fini_function(void * message_memory)
{
  msgs_srvs__srv__PWMServoState_Response__fini(message_memory);
}

size_t msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__size_function__PWMServoState_Response__state(
  const void * untyped_member)
{
  const msgs_srvs__msg__PWMServoState__Sequence * member =
    (const msgs_srvs__msg__PWMServoState__Sequence *)(untyped_member);
  return member->size;
}

const void * msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__get_const_function__PWMServoState_Response__state(
  const void * untyped_member, size_t index)
{
  const msgs_srvs__msg__PWMServoState__Sequence * member =
    (const msgs_srvs__msg__PWMServoState__Sequence *)(untyped_member);
  return &member->data[index];
}

void * msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__get_function__PWMServoState_Response__state(
  void * untyped_member, size_t index)
{
  msgs_srvs__msg__PWMServoState__Sequence * member =
    (msgs_srvs__msg__PWMServoState__Sequence *)(untyped_member);
  return &member->data[index];
}

void msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__fetch_function__PWMServoState_Response__state(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const msgs_srvs__msg__PWMServoState * item =
    ((const msgs_srvs__msg__PWMServoState *)
    msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__get_const_function__PWMServoState_Response__state(untyped_member, index));
  msgs_srvs__msg__PWMServoState * value =
    (msgs_srvs__msg__PWMServoState *)(untyped_value);
  *value = *item;
}

void msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__assign_function__PWMServoState_Response__state(
  void * untyped_member, size_t index, const void * untyped_value)
{
  msgs_srvs__msg__PWMServoState * item =
    ((msgs_srvs__msg__PWMServoState *)
    msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__get_function__PWMServoState_Response__state(untyped_member, index));
  const msgs_srvs__msg__PWMServoState * value =
    (const msgs_srvs__msg__PWMServoState *)(untyped_value);
  *item = *value;
}

bool msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__resize_function__PWMServoState_Response__state(
  void * untyped_member, size_t size)
{
  msgs_srvs__msg__PWMServoState__Sequence * member =
    (msgs_srvs__msg__PWMServoState__Sequence *)(untyped_member);
  msgs_srvs__msg__PWMServoState__Sequence__fini(member);
  return msgs_srvs__msg__PWMServoState__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__PWMServoState_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs_srvs__srv__PWMServoState_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msgs_srvs__srv__PWMServoState_Response, state),  // bytes offset in struct
    NULL,  // default value
    msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__size_function__PWMServoState_Response__state,  // size() function pointer
    msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__get_const_function__PWMServoState_Response__state,  // get_const(index) function pointer
    msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__get_function__PWMServoState_Response__state,  // get(index) function pointer
    msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__fetch_function__PWMServoState_Response__state,  // fetch(index, &value) function pointer
    msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__assign_function__PWMServoState_Response__state,  // assign(index, value) function pointer
    msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__resize_function__PWMServoState_Response__state  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__PWMServoState_Response_message_members = {
  "msgs_srvs__srv",  // message namespace
  "PWMServoState_Response",  // message name
  2,  // number of fields
  sizeof(msgs_srvs__srv__PWMServoState_Response),
  msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__PWMServoState_Response_message_member_array,  // message members
  msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__PWMServoState_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__PWMServoState_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__PWMServoState_Response_message_type_support_handle = {
  0,
  &msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__PWMServoState_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_msgs_srvs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs_srvs, srv, PWMServoState_Response)() {
  msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__PWMServoState_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs_srvs, msg, PWMServoState)();
  if (!msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__PWMServoState_Response_message_type_support_handle.typesupport_identifier) {
    msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__PWMServoState_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &msgs_srvs__srv__PWMServoState_Response__rosidl_typesupport_introspection_c__PWMServoState_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "msgs_srvs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "msgs_srvs/srv/detail/pwm_servo_state__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers msgs_srvs__srv__detail__pwm_servo_state__rosidl_typesupport_introspection_c__PWMServoState_service_members = {
  "msgs_srvs__srv",  // service namespace
  "PWMServoState",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // msgs_srvs__srv__detail__pwm_servo_state__rosidl_typesupport_introspection_c__PWMServoState_Request_message_type_support_handle,
  NULL  // response message
  // msgs_srvs__srv__detail__pwm_servo_state__rosidl_typesupport_introspection_c__PWMServoState_Response_message_type_support_handle
};

static rosidl_service_type_support_t msgs_srvs__srv__detail__pwm_servo_state__rosidl_typesupport_introspection_c__PWMServoState_service_type_support_handle = {
  0,
  &msgs_srvs__srv__detail__pwm_servo_state__rosidl_typesupport_introspection_c__PWMServoState_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs_srvs, srv, PWMServoState_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs_srvs, srv, PWMServoState_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_msgs_srvs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs_srvs, srv, PWMServoState)() {
  if (!msgs_srvs__srv__detail__pwm_servo_state__rosidl_typesupport_introspection_c__PWMServoState_service_type_support_handle.typesupport_identifier) {
    msgs_srvs__srv__detail__pwm_servo_state__rosidl_typesupport_introspection_c__PWMServoState_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)msgs_srvs__srv__detail__pwm_servo_state__rosidl_typesupport_introspection_c__PWMServoState_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs_srvs, srv, PWMServoState_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msgs_srvs, srv, PWMServoState_Response)()->data;
  }

  return &msgs_srvs__srv__detail__pwm_servo_state__rosidl_typesupport_introspection_c__PWMServoState_service_type_support_handle;
}
