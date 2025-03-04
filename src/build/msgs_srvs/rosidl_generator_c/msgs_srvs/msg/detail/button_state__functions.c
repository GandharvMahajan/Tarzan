// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from msgs_srvs:msg/ButtonState.idl
// generated code does not contain a copyright notice
#include "msgs_srvs/msg/detail/button_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
msgs_srvs__msg__ButtonState__init(msgs_srvs__msg__ButtonState * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // state
  return true;
}

void
msgs_srvs__msg__ButtonState__fini(msgs_srvs__msg__ButtonState * msg)
{
  if (!msg) {
    return;
  }
  // id
  // state
}

bool
msgs_srvs__msg__ButtonState__are_equal(const msgs_srvs__msg__ButtonState * lhs, const msgs_srvs__msg__ButtonState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  return true;
}

bool
msgs_srvs__msg__ButtonState__copy(
  const msgs_srvs__msg__ButtonState * input,
  msgs_srvs__msg__ButtonState * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // state
  output->state = input->state;
  return true;
}

msgs_srvs__msg__ButtonState *
msgs_srvs__msg__ButtonState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs_srvs__msg__ButtonState * msg = (msgs_srvs__msg__ButtonState *)allocator.allocate(sizeof(msgs_srvs__msg__ButtonState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(msgs_srvs__msg__ButtonState));
  bool success = msgs_srvs__msg__ButtonState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
msgs_srvs__msg__ButtonState__destroy(msgs_srvs__msg__ButtonState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    msgs_srvs__msg__ButtonState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
msgs_srvs__msg__ButtonState__Sequence__init(msgs_srvs__msg__ButtonState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs_srvs__msg__ButtonState * data = NULL;

  if (size) {
    data = (msgs_srvs__msg__ButtonState *)allocator.zero_allocate(size, sizeof(msgs_srvs__msg__ButtonState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = msgs_srvs__msg__ButtonState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        msgs_srvs__msg__ButtonState__fini(&data[i - 1]);
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
msgs_srvs__msg__ButtonState__Sequence__fini(msgs_srvs__msg__ButtonState__Sequence * array)
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
      msgs_srvs__msg__ButtonState__fini(&array->data[i]);
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

msgs_srvs__msg__ButtonState__Sequence *
msgs_srvs__msg__ButtonState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msgs_srvs__msg__ButtonState__Sequence * array = (msgs_srvs__msg__ButtonState__Sequence *)allocator.allocate(sizeof(msgs_srvs__msg__ButtonState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = msgs_srvs__msg__ButtonState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
msgs_srvs__msg__ButtonState__Sequence__destroy(msgs_srvs__msg__ButtonState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    msgs_srvs__msg__ButtonState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
msgs_srvs__msg__ButtonState__Sequence__are_equal(const msgs_srvs__msg__ButtonState__Sequence * lhs, const msgs_srvs__msg__ButtonState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!msgs_srvs__msg__ButtonState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
msgs_srvs__msg__ButtonState__Sequence__copy(
  const msgs_srvs__msg__ButtonState__Sequence * input,
  msgs_srvs__msg__ButtonState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(msgs_srvs__msg__ButtonState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    msgs_srvs__msg__ButtonState * data =
      (msgs_srvs__msg__ButtonState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!msgs_srvs__msg__ButtonState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          msgs_srvs__msg__ButtonState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!msgs_srvs__msg__ButtonState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
