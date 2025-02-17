// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from msgs_srvs:srv/PWMServoState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__SRV__DETAIL__PWM_SERVO_STATE__STRUCT_HPP_
#define MSGS_SRVS__SRV__DETAIL__PWM_SERVO_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'cmd'
#include "msgs_srvs/msg/detail/pwm_servo_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__msgs_srvs__srv__PWMServoState_Request __attribute__((deprecated))
#else
# define DEPRECATED__msgs_srvs__srv__PWMServoState_Request __declspec(deprecated)
#endif

namespace msgs_srvs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PWMServoState_Request_
{
  using Type = PWMServoState_Request_<ContainerAllocator>;

  explicit PWMServoState_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit PWMServoState_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _cmd_type =
    std::vector<msgs_srvs::msg::PWMServoState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<msgs_srvs::msg::PWMServoState_<ContainerAllocator>>>;
  _cmd_type cmd;

  // setters for named parameter idiom
  Type & set__cmd(
    const std::vector<msgs_srvs::msg::PWMServoState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<msgs_srvs::msg::PWMServoState_<ContainerAllocator>>> & _arg)
  {
    this->cmd = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    msgs_srvs::srv::PWMServoState_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const msgs_srvs::srv::PWMServoState_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<msgs_srvs::srv::PWMServoState_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<msgs_srvs::srv::PWMServoState_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      msgs_srvs::srv::PWMServoState_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<msgs_srvs::srv::PWMServoState_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      msgs_srvs::srv::PWMServoState_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<msgs_srvs::srv::PWMServoState_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<msgs_srvs::srv::PWMServoState_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<msgs_srvs::srv::PWMServoState_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__msgs_srvs__srv__PWMServoState_Request
    std::shared_ptr<msgs_srvs::srv::PWMServoState_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__msgs_srvs__srv__PWMServoState_Request
    std::shared_ptr<msgs_srvs::srv::PWMServoState_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PWMServoState_Request_ & other) const
  {
    if (this->cmd != other.cmd) {
      return false;
    }
    return true;
  }
  bool operator!=(const PWMServoState_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PWMServoState_Request_

// alias to use template instance with default allocator
using PWMServoState_Request =
  msgs_srvs::srv::PWMServoState_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace msgs_srvs


// Include directives for member types
// Member 'state'
// already included above
// #include "msgs_srvs/msg/detail/pwm_servo_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__msgs_srvs__srv__PWMServoState_Response __attribute__((deprecated))
#else
# define DEPRECATED__msgs_srvs__srv__PWMServoState_Response __declspec(deprecated)
#endif

namespace msgs_srvs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PWMServoState_Response_
{
  using Type = PWMServoState_Response_<ContainerAllocator>;

  explicit PWMServoState_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit PWMServoState_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _state_type =
    std::vector<msgs_srvs::msg::PWMServoState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<msgs_srvs::msg::PWMServoState_<ContainerAllocator>>>;
  _state_type state;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__state(
    const std::vector<msgs_srvs::msg::PWMServoState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<msgs_srvs::msg::PWMServoState_<ContainerAllocator>>> & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    msgs_srvs::srv::PWMServoState_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const msgs_srvs::srv::PWMServoState_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<msgs_srvs::srv::PWMServoState_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<msgs_srvs::srv::PWMServoState_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      msgs_srvs::srv::PWMServoState_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<msgs_srvs::srv::PWMServoState_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      msgs_srvs::srv::PWMServoState_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<msgs_srvs::srv::PWMServoState_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<msgs_srvs::srv::PWMServoState_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<msgs_srvs::srv::PWMServoState_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__msgs_srvs__srv__PWMServoState_Response
    std::shared_ptr<msgs_srvs::srv::PWMServoState_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__msgs_srvs__srv__PWMServoState_Response
    std::shared_ptr<msgs_srvs::srv::PWMServoState_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PWMServoState_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const PWMServoState_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PWMServoState_Response_

// alias to use template instance with default allocator
using PWMServoState_Response =
  msgs_srvs::srv::PWMServoState_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace msgs_srvs

namespace msgs_srvs
{

namespace srv
{

struct PWMServoState
{
  using Request = msgs_srvs::srv::PWMServoState_Request;
  using Response = msgs_srvs::srv::PWMServoState_Response;
};

}  // namespace srv

}  // namespace msgs_srvs

#endif  // MSGS_SRVS__SRV__DETAIL__PWM_SERVO_STATE__STRUCT_HPP_
