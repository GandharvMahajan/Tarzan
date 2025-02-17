// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from msgs_srvs:srv/PWMServoState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__SRV__DETAIL__PWM_SERVO_STATE__FUNCTIONS_H_
#define MSGS_SRVS__SRV__DETAIL__PWM_SERVO_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "msgs_srvs/msg/rosidl_generator_c__visibility_control.h"

#include "msgs_srvs/srv/detail/pwm_servo_state__struct.h"

/// Initialize srv/PWMServoState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * msgs_srvs__srv__PWMServoState_Request
 * )) before or use
 * msgs_srvs__srv__PWMServoState_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__srv__PWMServoState_Request__init(msgs_srvs__srv__PWMServoState_Request * msg);

/// Finalize srv/PWMServoState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
void
msgs_srvs__srv__PWMServoState_Request__fini(msgs_srvs__srv__PWMServoState_Request * msg);

/// Create srv/PWMServoState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * msgs_srvs__srv__PWMServoState_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
msgs_srvs__srv__PWMServoState_Request *
msgs_srvs__srv__PWMServoState_Request__create();

/// Destroy srv/PWMServoState message.
/**
 * It calls
 * msgs_srvs__srv__PWMServoState_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
void
msgs_srvs__srv__PWMServoState_Request__destroy(msgs_srvs__srv__PWMServoState_Request * msg);

/// Check for srv/PWMServoState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__srv__PWMServoState_Request__are_equal(const msgs_srvs__srv__PWMServoState_Request * lhs, const msgs_srvs__srv__PWMServoState_Request * rhs);

/// Copy a srv/PWMServoState message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__srv__PWMServoState_Request__copy(
  const msgs_srvs__srv__PWMServoState_Request * input,
  msgs_srvs__srv__PWMServoState_Request * output);

/// Initialize array of srv/PWMServoState messages.
/**
 * It allocates the memory for the number of elements and calls
 * msgs_srvs__srv__PWMServoState_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__srv__PWMServoState_Request__Sequence__init(msgs_srvs__srv__PWMServoState_Request__Sequence * array, size_t size);

/// Finalize array of srv/PWMServoState messages.
/**
 * It calls
 * msgs_srvs__srv__PWMServoState_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
void
msgs_srvs__srv__PWMServoState_Request__Sequence__fini(msgs_srvs__srv__PWMServoState_Request__Sequence * array);

/// Create array of srv/PWMServoState messages.
/**
 * It allocates the memory for the array and calls
 * msgs_srvs__srv__PWMServoState_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
msgs_srvs__srv__PWMServoState_Request__Sequence *
msgs_srvs__srv__PWMServoState_Request__Sequence__create(size_t size);

/// Destroy array of srv/PWMServoState messages.
/**
 * It calls
 * msgs_srvs__srv__PWMServoState_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
void
msgs_srvs__srv__PWMServoState_Request__Sequence__destroy(msgs_srvs__srv__PWMServoState_Request__Sequence * array);

/// Check for srv/PWMServoState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__srv__PWMServoState_Request__Sequence__are_equal(const msgs_srvs__srv__PWMServoState_Request__Sequence * lhs, const msgs_srvs__srv__PWMServoState_Request__Sequence * rhs);

/// Copy an array of srv/PWMServoState messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__srv__PWMServoState_Request__Sequence__copy(
  const msgs_srvs__srv__PWMServoState_Request__Sequence * input,
  msgs_srvs__srv__PWMServoState_Request__Sequence * output);

/// Initialize srv/PWMServoState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * msgs_srvs__srv__PWMServoState_Response
 * )) before or use
 * msgs_srvs__srv__PWMServoState_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__srv__PWMServoState_Response__init(msgs_srvs__srv__PWMServoState_Response * msg);

/// Finalize srv/PWMServoState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
void
msgs_srvs__srv__PWMServoState_Response__fini(msgs_srvs__srv__PWMServoState_Response * msg);

/// Create srv/PWMServoState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * msgs_srvs__srv__PWMServoState_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
msgs_srvs__srv__PWMServoState_Response *
msgs_srvs__srv__PWMServoState_Response__create();

/// Destroy srv/PWMServoState message.
/**
 * It calls
 * msgs_srvs__srv__PWMServoState_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
void
msgs_srvs__srv__PWMServoState_Response__destroy(msgs_srvs__srv__PWMServoState_Response * msg);

/// Check for srv/PWMServoState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__srv__PWMServoState_Response__are_equal(const msgs_srvs__srv__PWMServoState_Response * lhs, const msgs_srvs__srv__PWMServoState_Response * rhs);

/// Copy a srv/PWMServoState message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__srv__PWMServoState_Response__copy(
  const msgs_srvs__srv__PWMServoState_Response * input,
  msgs_srvs__srv__PWMServoState_Response * output);

/// Initialize array of srv/PWMServoState messages.
/**
 * It allocates the memory for the number of elements and calls
 * msgs_srvs__srv__PWMServoState_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__srv__PWMServoState_Response__Sequence__init(msgs_srvs__srv__PWMServoState_Response__Sequence * array, size_t size);

/// Finalize array of srv/PWMServoState messages.
/**
 * It calls
 * msgs_srvs__srv__PWMServoState_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
void
msgs_srvs__srv__PWMServoState_Response__Sequence__fini(msgs_srvs__srv__PWMServoState_Response__Sequence * array);

/// Create array of srv/PWMServoState messages.
/**
 * It allocates the memory for the array and calls
 * msgs_srvs__srv__PWMServoState_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
msgs_srvs__srv__PWMServoState_Response__Sequence *
msgs_srvs__srv__PWMServoState_Response__Sequence__create(size_t size);

/// Destroy array of srv/PWMServoState messages.
/**
 * It calls
 * msgs_srvs__srv__PWMServoState_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
void
msgs_srvs__srv__PWMServoState_Response__Sequence__destroy(msgs_srvs__srv__PWMServoState_Response__Sequence * array);

/// Check for srv/PWMServoState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__srv__PWMServoState_Response__Sequence__are_equal(const msgs_srvs__srv__PWMServoState_Response__Sequence * lhs, const msgs_srvs__srv__PWMServoState_Response__Sequence * rhs);

/// Copy an array of srv/PWMServoState messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__srv__PWMServoState_Response__Sequence__copy(
  const msgs_srvs__srv__PWMServoState_Response__Sequence * input,
  msgs_srvs__srv__PWMServoState_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MSGS_SRVS__SRV__DETAIL__PWM_SERVO_STATE__FUNCTIONS_H_
