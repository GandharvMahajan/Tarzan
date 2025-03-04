// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from msgs_srvs:msg/PWMServoStateDuration.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE_DURATION__FUNCTIONS_H_
#define MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE_DURATION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "msgs_srvs/msg/rosidl_generator_c__visibility_control.h"

#include "msgs_srvs/msg/detail/pwm_servo_state_duration__struct.h"

/// Initialize msg/PWMServoStateDuration message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * msgs_srvs__msg__PWMServoStateDuration
 * )) before or use
 * msgs_srvs__msg__PWMServoStateDuration__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__msg__PWMServoStateDuration__init(msgs_srvs__msg__PWMServoStateDuration * msg);

/// Finalize msg/PWMServoStateDuration message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
void
msgs_srvs__msg__PWMServoStateDuration__fini(msgs_srvs__msg__PWMServoStateDuration * msg);

/// Create msg/PWMServoStateDuration message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * msgs_srvs__msg__PWMServoStateDuration__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
msgs_srvs__msg__PWMServoStateDuration *
msgs_srvs__msg__PWMServoStateDuration__create();

/// Destroy msg/PWMServoStateDuration message.
/**
 * It calls
 * msgs_srvs__msg__PWMServoStateDuration__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
void
msgs_srvs__msg__PWMServoStateDuration__destroy(msgs_srvs__msg__PWMServoStateDuration * msg);

/// Check for msg/PWMServoStateDuration message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__msg__PWMServoStateDuration__are_equal(const msgs_srvs__msg__PWMServoStateDuration * lhs, const msgs_srvs__msg__PWMServoStateDuration * rhs);

/// Copy a msg/PWMServoStateDuration message.
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
msgs_srvs__msg__PWMServoStateDuration__copy(
  const msgs_srvs__msg__PWMServoStateDuration * input,
  msgs_srvs__msg__PWMServoStateDuration * output);

/// Initialize array of msg/PWMServoStateDuration messages.
/**
 * It allocates the memory for the number of elements and calls
 * msgs_srvs__msg__PWMServoStateDuration__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__msg__PWMServoStateDuration__Sequence__init(msgs_srvs__msg__PWMServoStateDuration__Sequence * array, size_t size);

/// Finalize array of msg/PWMServoStateDuration messages.
/**
 * It calls
 * msgs_srvs__msg__PWMServoStateDuration__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
void
msgs_srvs__msg__PWMServoStateDuration__Sequence__fini(msgs_srvs__msg__PWMServoStateDuration__Sequence * array);

/// Create array of msg/PWMServoStateDuration messages.
/**
 * It allocates the memory for the array and calls
 * msgs_srvs__msg__PWMServoStateDuration__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
msgs_srvs__msg__PWMServoStateDuration__Sequence *
msgs_srvs__msg__PWMServoStateDuration__Sequence__create(size_t size);

/// Destroy array of msg/PWMServoStateDuration messages.
/**
 * It calls
 * msgs_srvs__msg__PWMServoStateDuration__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
void
msgs_srvs__msg__PWMServoStateDuration__Sequence__destroy(msgs_srvs__msg__PWMServoStateDuration__Sequence * array);

/// Check for msg/PWMServoStateDuration message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__msg__PWMServoStateDuration__Sequence__are_equal(const msgs_srvs__msg__PWMServoStateDuration__Sequence * lhs, const msgs_srvs__msg__PWMServoStateDuration__Sequence * rhs);

/// Copy an array of msg/PWMServoStateDuration messages.
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
msgs_srvs__msg__PWMServoStateDuration__Sequence__copy(
  const msgs_srvs__msg__PWMServoStateDuration__Sequence * input,
  msgs_srvs__msg__PWMServoStateDuration__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE_DURATION__FUNCTIONS_H_
