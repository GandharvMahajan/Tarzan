// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from msgs_srvs:msg/MotorsState.idl
// generated code does not contain a copyright notice
#include "msgs_srvs/msg/detail/motors_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `data`
#include "msgs_srvs/msg/detail/motor_state__functions.h"

bool
msgs_srvs__msg__MotorsState__init(msgs_srvs__msg__MotorsState * msg)
{
  if (!msg) {
    return false;
  }
  // data
  if (!msgs_srvs__msg__MotorState__Sequence__init(&msg->data, 0)) {
    msgs_srvs__msg__MotorsState__fini(msg);
    return false;
  }
  return true;
}

void
msgs_srvs__msg__MotorsState__fini(msgs_srvs__msg__MotorsState * msg)
{
  if (!msg) {
    return;
  }
  // data
  msgs_srvs__msg__MotorState__Sequence__fini(&msg->data);
}

bool
msgs_srvs__msg__MotorsState__are_equal(const msgs_srvs__msg__MotorsState * lhs, const msgs_srvs__msg__MotorsState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // data
  if (!msgs_srvs__msg__MotorState__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
msgs_srvs__msg__MotorsState__copy(
  const msgs_srvs__msg__MotorsState * input,
  msgs_srvs__msg__MotorsState * output)
{
  if (!input || !output) {
    return false;
  }
  // data
  if (!msgs_srvs__msg__MotorState__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

msgs_srvs__msg__MotorsState *
msgs_srvs__msg__MotorsState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs_srvs__msg__MotorsState * msg = (msgs_srvs__msg__MotorsState *)allocator.allocate(sizeof(msgs_srvs__msg__MotorsState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(msgs_srvs__msg__MotorsState));
  bool success = msgs_srvs__msg__MotorsState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
msgs_srvs__msg__MotorsState__destroy(msgs_srvs__msg__MotorsState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    msgs_srvs__msg__MotorsState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
msgs_srvs__msg__MotorsState__Sequence__init(msgs_srvs__msg__MotorsState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs_srvs__msg__MotorsState * data = NULL;

  if (size) {
    data = (msgs_srvs__msg__MotorsState *)allocator.zero_allocate(size, sizeof(msgs_srvs__msg__MotorsState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = msgs_srvs__msg__MotorsState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        msgs_srvs__msg__MotorsState__fini(&data[i - 1]);
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
msgs_srvs__msg__MotorsState__Sequence__fini(msgs_srvs__msg__MotorsState__Sequence * array)
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
      msgs_srvs__msg__MotorsState__fini(&array->data[i]);
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

msgs_srvs__msg__MotorsState__Sequence *
msgs_srvs__msg__MotorsState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs_srvs__msg__MotorsState__Sequence * array = (msgs_srvs__msg__MotorsState__Sequence *)allocator.allocate(sizeof(msgs_srvs__msg__MotorsState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = msgs_srvs__msg__MotorsState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
msgs_srvs__msg__MotorsState__Sequence__destroy(msgs_srvs__msg__MotorsState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    msgs_srvs__msg__MotorsState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
msgs_srvs__msg__MotorsState__Sequence__are_equal(const msgs_srvs__msg__MotorsState__Sequence * lhs, const msgs_srvs__msg__MotorsState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!msgs_srvs__msg__MotorsState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
msgs_srvs__msg__MotorsState__Sequence__copy(
  const msgs_srvs__msg__MotorsState__Sequence * input,
  msgs_srvs__msg__MotorsState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(msgs_srvs__msg__MotorsState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    msgs_srvs__msg__MotorsState * data =
      (msgs_srvs__msg__MotorsState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!msgs_srvs__msg__MotorsState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          msgs_srvs__msg__MotorsState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!msgs_srvs__msg__MotorsState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
