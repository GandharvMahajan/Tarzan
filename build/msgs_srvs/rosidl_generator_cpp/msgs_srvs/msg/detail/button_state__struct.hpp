// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from msgs_srvs:msg/ButtonState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__BUTTON_STATE__STRUCT_HPP_
#define MSGS_SRVS__MSG__DETAIL__BUTTON_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__msgs_srvs__msg__ButtonState __attribute__((deprecated))
#else
# define DEPRECATED__msgs_srvs__msg__ButtonState __declspec(deprecated)
#endif

namespace msgs_srvs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ButtonState_
{
  using Type = ButtonState_<ContainerAllocator>;

  explicit ButtonState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->state = 0;
    }
  }

  explicit ButtonState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0;
      this->state = 0;
    }
  }

  // field types and members
  using _id_type =
    uint8_t;
  _id_type id;
  using _state_type =
    uint8_t;
  _state_type state;

  // setters for named parameter idiom
  Type & set__id(
    const uint8_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__state(
    const uint8_t & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    msgs_srvs::msg::ButtonState_<ContainerAllocator> *;
  using ConstRawPtr =
    const msgs_srvs::msg::ButtonState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<msgs_srvs::msg::ButtonState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<msgs_srvs::msg::ButtonState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      msgs_srvs::msg::ButtonState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<msgs_srvs::msg::ButtonState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      msgs_srvs::msg::ButtonState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<msgs_srvs::msg::ButtonState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<msgs_srvs::msg::ButtonState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<msgs_srvs::msg::ButtonState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__msgs_srvs__msg__ButtonState
    std::shared_ptr<msgs_srvs::msg::ButtonState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__msgs_srvs__msg__ButtonState
    std::shared_ptr<msgs_srvs::msg::ButtonState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ButtonState_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const ButtonState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ButtonState_

// alias to use template instance with default allocator
using ButtonState =
  msgs_srvs::msg::ButtonState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace msgs_srvs

#endif  // MSGS_SRVS__MSG__DETAIL__BUTTON_STATE__STRUCT_HPP_
