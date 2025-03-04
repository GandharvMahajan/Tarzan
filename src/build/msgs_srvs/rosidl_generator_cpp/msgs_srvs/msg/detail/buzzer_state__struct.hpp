// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from msgs_srvs:msg/BuzzerState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__BUZZER_STATE__STRUCT_HPP_
#define MSGS_SRVS__MSG__DETAIL__BUZZER_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__msgs_srvs__msg__BuzzerState __attribute__((deprecated))
#else
# define DEPRECATED__msgs_srvs__msg__BuzzerState __declspec(deprecated)
#endif

namespace msgs_srvs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BuzzerState_
{
  using Type = BuzzerState_<ContainerAllocator>;

  explicit BuzzerState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->freq = 0;
      this->on_time = 0.0f;
      this->off_time = 0.0f;
      this->repeat = 0;
    }
  }

  explicit BuzzerState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->freq = 0;
      this->on_time = 0.0f;
      this->off_time = 0.0f;
      this->repeat = 0;
    }
  }

  // field types and members
  using _freq_type =
    uint16_t;
  _freq_type freq;
  using _on_time_type =
    float;
  _on_time_type on_time;
  using _off_time_type =
    float;
  _off_time_type off_time;
  using _repeat_type =
    uint16_t;
  _repeat_type repeat;

  // setters for named parameter idiom
  Type & set__freq(
    const uint16_t & _arg)
  {
    this->freq = _arg;
    return *this;
  }
  Type & set__on_time(
    const float & _arg)
  {
    this->on_time = _arg;
    return *this;
  }
  Type & set__off_time(
    const float & _arg)
  {
    this->off_time = _arg;
    return *this;
  }
  Type & set__repeat(
    const uint16_t & _arg)
  {
    this->repeat = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    msgs_srvs::msg::BuzzerState_<ContainerAllocator> *;
  using ConstRawPtr =
    const msgs_srvs::msg::BuzzerState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<msgs_srvs::msg::BuzzerState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<msgs_srvs::msg::BuzzerState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      msgs_srvs::msg::BuzzerState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<msgs_srvs::msg::BuzzerState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      msgs_srvs::msg::BuzzerState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<msgs_srvs::msg::BuzzerState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<msgs_srvs::msg::BuzzerState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<msgs_srvs::msg::BuzzerState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__msgs_srvs__msg__BuzzerState
    std::shared_ptr<msgs_srvs::msg::BuzzerState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__msgs_srvs__msg__BuzzerState
    std::shared_ptr<msgs_srvs::msg::BuzzerState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BuzzerState_ & other) const
  {
    if (this->freq != other.freq) {
      return false;
    }
    if (this->on_time != other.on_time) {
      return false;
    }
    if (this->off_time != other.off_time) {
      return false;
    }
    if (this->repeat != other.repeat) {
      return false;
    }
    return true;
  }
  bool operator!=(const BuzzerState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BuzzerState_

// alias to use template instance with default allocator
using BuzzerState =
  msgs_srvs::msg::BuzzerState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace msgs_srvs

#endif  // MSGS_SRVS__MSG__DETAIL__BUZZER_STATE__STRUCT_HPP_
