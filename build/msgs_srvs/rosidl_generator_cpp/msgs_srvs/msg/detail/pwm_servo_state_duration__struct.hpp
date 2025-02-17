// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from msgs_srvs:msg/PWMServoStateDuration.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE_DURATION__STRUCT_HPP_
#define MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE_DURATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'state'
#include "msgs_srvs/msg/detail/pwm_servo_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__msgs_srvs__msg__PWMServoStateDuration __attribute__((deprecated))
#else
# define DEPRECATED__msgs_srvs__msg__PWMServoStateDuration __declspec(deprecated)
#endif

namespace msgs_srvs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PWMServoStateDuration_
{
  using Type = PWMServoStateDuration_<ContainerAllocator>;

  explicit PWMServoStateDuration_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->duration = 0.0;
    }
  }

  explicit PWMServoStateDuration_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->duration = 0.0;
    }
  }

  // field types and members
  using _state_type =
    std::vector<msgs_srvs::msg::PWMServoState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<msgs_srvs::msg::PWMServoState_<ContainerAllocator>>>;
  _state_type state;
  using _duration_type =
    double;
  _duration_type duration;

  // setters for named parameter idiom
  Type & set__state(
    const std::vector<msgs_srvs::msg::PWMServoState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<msgs_srvs::msg::PWMServoState_<ContainerAllocator>>> & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__duration(
    const double & _arg)
  {
    this->duration = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    msgs_srvs::msg::PWMServoStateDuration_<ContainerAllocator> *;
  using ConstRawPtr =
    const msgs_srvs::msg::PWMServoStateDuration_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<msgs_srvs::msg::PWMServoStateDuration_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<msgs_srvs::msg::PWMServoStateDuration_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      msgs_srvs::msg::PWMServoStateDuration_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<msgs_srvs::msg::PWMServoStateDuration_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      msgs_srvs::msg::PWMServoStateDuration_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<msgs_srvs::msg::PWMServoStateDuration_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<msgs_srvs::msg::PWMServoStateDuration_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<msgs_srvs::msg::PWMServoStateDuration_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__msgs_srvs__msg__PWMServoStateDuration
    std::shared_ptr<msgs_srvs::msg::PWMServoStateDuration_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__msgs_srvs__msg__PWMServoStateDuration
    std::shared_ptr<msgs_srvs::msg::PWMServoStateDuration_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PWMServoStateDuration_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    if (this->duration != other.duration) {
      return false;
    }
    return true;
  }
  bool operator!=(const PWMServoStateDuration_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PWMServoStateDuration_

// alias to use template instance with default allocator
using PWMServoStateDuration =
  msgs_srvs::msg::PWMServoStateDuration_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace msgs_srvs

#endif  // MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE_DURATION__STRUCT_HPP_
