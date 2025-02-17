// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from msgs_srvs:msg/PWMServoState.idl
// generated code does not contain a copyright notice
#include "msgs_srvs/msg/detail/pwm_servo_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
msgs_srvs__msg__PWMServoState__init(msgs_srvs__msg__PWMServoState * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // position
  // offset
  return true;
}

void
msgs_srvs__msg__PWMServoState__fini(msgs_srvs__msg__PWMServoState * msg)
{
  if (!msg) {
    return;
  }
  // id
  // position
  // offset
}

bool
msgs_srvs__msg__PWMServoState__are_equal(const msgs_srvs__msg__PWMServoState * lhs, const msgs_srvs__msg__PWMServoState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // position
  if (lhs->position != rhs->position) {
    return false;
  }
  // offset
  if (lhs->offset != rhs->offset) {
    return false;
  }
  return true;
}

bool
msgs_srvs__msg__PWMServoState__copy(
  const msgs_srvs__msg__PWMServoState * input,
  msgs_srvs__msg__PWMServoState * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // position
  output->position = input->position;
  // offset
  output->offset = input->offset;
  return true;
}

msgs_srvs__msg__PWMServoState *
msgs_srvs__msg__PWMServoState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs_srvs__msg__PWMServoState * msg = (msgs_srvs__msg__PWMServoState *)allocator.allocate(sizeof(msgs_srvs__msg__PWMServoState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(msgs_srvs__msg__PWMServoState));
  bool success = msgs_srvs__msg__PWMServoState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
msgs_srvs__msg__PWMServoState__destroy(msgs_srvs__msg__PWMServoState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    msgs_srvs__msg__PWMServoState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
msgs_srvs__msg__PWMServoState__Sequence__init(msgs_srvs__msg__PWMServoState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs_srvs__msg__PWMServoState * data = NULL;

  if (size) {
    data = (msgs_srvs__msg__PWMServoState *)allocator.zero_allocate(size, sizeof(msgs_srvs__msg__PWMServoState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = msgs_srvs__msg__PWMServoState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        msgs_srvs__msg__PWMServoState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
msgs_srvs__msg__PWMServoState__Sequence__fini(msgs_srvs__msg__PWMServoState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      msgs_srvs__msg__PWMServoState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

msgs_srvs__msg__PWMServoState__Sequence *
msgs_srvs__msg__PWMServoState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs_srvs__msg__PWMServoState__Sequence * array = (msgs_srvs__msg__PWMServoState__Sequence *)allocator.allocate(sizeof(msgs_srvs__msg__PWMServoState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = msgs_srvs__msg__PWMServoState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
msgs_srvs__msg__PWMServoState__Sequence__destroy(msgs_srvs__msg__PWMServoState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    msgs_srvs__msg__PWMServoState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
msgs_srvs__msg__PWMServoState__Sequence__are_equal(const msgs_srvs__msg__PWMServoState__Sequence * lhs, const msgs_srvs__msg__PWMServoState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!msgs_srvs__msg__PWMServoState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
msgs_srvs__msg__PWMServoState__Sequence__copy(
  const msgs_srvs__msg__PWMServoState__Sequence * input,
  msgs_srvs__msg__PWMServoState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(msgs_srvs__msg__PWMServoState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    msgs_srvs__msg__PWMServoState * data =
      (msgs_srvs__msg__PWMServoState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!msgs_srvs__msg__PWMServoState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          msgs_srvs__msg__PWMServoState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!msgs_srvs__msg__PWMServoState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
