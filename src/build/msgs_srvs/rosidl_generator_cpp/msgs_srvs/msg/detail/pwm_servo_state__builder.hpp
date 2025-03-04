// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs_srvs:msg/PWMServoState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE__BUILDER_HPP_
#define MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs_srvs/msg/detail/pwm_servo_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs_srvs
{

namespace msg
{

namespace builder
{

class Init_PWMServoState_offset
{
public:
  explicit Init_PWMServoState_offset(::msgs_srvs::msg::PWMServoState & msg)
  : msg_(msg)
  {}
  ::msgs_srvs::msg::PWMServoState offset(::msgs_srvs::msg::PWMServoState::_offset_type arg)
  {
    msg_.offset = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs_srvs::msg::PWMServoState msg_;
};

class Init_PWMServoState_position
{
public:
  explicit Init_PWMServoState_position(::msgs_srvs::msg::PWMServoState & msg)
  : msg_(msg)
  {}
  Init_PWMServoState_offset position(::msgs_srvs::msg::PWMServoState::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_PWMServoState_offset(msg_);
  }

private:
  ::msgs_srvs::msg::PWMServoState msg_;
};

class Init_PWMServoState_id
{
public:
  Init_PWMServoState_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PWMServoState_position id(::msgs_srvs::msg::PWMServoState::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_PWMServoState_position(msg_);
  }

private:
  ::msgs_srvs::msg::PWMServoState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs_srvs::msg::PWMServoState>()
{
  return msgs_srvs::msg::builder::Init_PWMServoState_id();
}

}  // namespace msgs_srvs

#endif  // MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE__BUILDER_HPP_
