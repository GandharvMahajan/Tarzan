// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from msgs_srvs:msg/PWMServoState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE__FUNCTIONS_H_
#define MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "msgs_srvs/msg/rosidl_generator_c__visibility_control.h"

#include "msgs_srvs/msg/detail/pwm_servo_state__struct.h"

/// Initialize msg/PWMServoState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * msgs_srvs__msg__PWMServoState
 * )) before or use
 * msgs_srvs__msg__PWMServoState__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__msg__PWMServoState__init(msgs_srvs__msg__PWMServoState * msg);

/// Finalize msg/PWMServoState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
void
msgs_srvs__msg__PWMServoState__fini(msgs_srvs__msg__PWMServoState * msg);

/// Create msg/PWMServoState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * msgs_srvs__msg__PWMServoState__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
msgs_srvs__msg__PWMServoState *
msgs_srvs__msg__PWMServoState__create();

/// Destroy msg/PWMServoState message.
/**
 * It calls
 * msgs_srvs__msg__PWMServoState__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
void
msgs_srvs__msg__PWMServoState__destroy(msgs_srvs__msg__PWMServoState * msg);

/// Check for msg/PWMServoState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__msg__PWMServoState__are_equal(const msgs_srvs__msg__PWMServoState * lhs, const msgs_srvs__msg__PWMServoState * rhs);

/// Copy a msg/PWMServoState message.
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
msgs_srvs__msg__PWMServoState__copy(
  const msgs_srvs__msg__PWMServoState * input,
  msgs_srvs__msg__PWMServoState * output);

/// Initialize array of msg/PWMServoState messages.
/**
 * It allocates the memory for the number of elements and calls
 * msgs_srvs__msg__PWMServoState__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__msg__PWMServoState__Sequence__init(msgs_srvs__msg__PWMServoState__Sequence * array, size_t size);

/// Finalize array of msg/PWMServoState messages.
/**
 * It calls
 * msgs_srvs__msg__PWMServoState__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
void
msgs_srvs__msg__PWMServoState__Sequence__fini(msgs_srvs__msg__PWMServoState__Sequence * array);

/// Create array of msg/PWMServoState messages.
/**
 * It allocates the memory for the array and calls
 * msgs_srvs__msg__PWMServoState__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
msgs_srvs__msg__PWMServoState__Sequence *
msgs_srvs__msg__PWMServoState__Sequence__create(size_t size);

/// Destroy array of msg/PWMServoState messages.
/**
 * It calls
 * msgs_srvs__msg__PWMServoState__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
void
msgs_srvs__msg__PWMServoState__Sequence__destroy(msgs_srvs__msg__PWMServoState__Sequence * array);

/// Check for msg/PWMServoState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_msgs_srvs
bool
msgs_srvs__msg__PWMServoState__Sequence__are_equal(const msgs_srvs__msg__PWMServoState__Sequence * lhs, const msgs_srvs__msg__PWMServoState__Sequence * rhs);

/// Copy an array of msg/PWMServoState messages.
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
msgs_srvs__msg__PWMServoState__Sequence__copy(
  const msgs_srvs__msg__PWMServoState__Sequence * input,
  msgs_srvs__msg__PWMServoState__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE__FUNCTIONS_H_
