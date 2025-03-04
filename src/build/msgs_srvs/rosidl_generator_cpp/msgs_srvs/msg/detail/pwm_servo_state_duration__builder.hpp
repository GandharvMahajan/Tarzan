// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs_srvs:msg/PWMServoStateDuration.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE_DURATION__BUILDER_HPP_
#define MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE_DURATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs_srvs/msg/detail/pwm_servo_state_duration__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs_srvs
{

namespace msg
{

namespace builder
{

class Init_PWMServoStateDuration_duration
{
public:
  explicit Init_PWMServoStateDuration_duration(::msgs_srvs::msg::PWMServoStateDuration & msg)
  : msg_(msg)
  {}
  ::msgs_srvs::msg::PWMServoStateDuration duration(::msgs_srvs::msg::PWMServoStateDuration::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs_srvs::msg::PWMServoStateDuration msg_;
};

class Init_PWMServoStateDuration_state
{
public:
  Init_PWMServoStateDuration_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PWMServoStateDuration_duration state(::msgs_srvs::msg::PWMServoStateDuration::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_PWMServoStateDuration_duration(msg_);
  }

private:
  ::msgs_srvs::msg::PWMServoStateDuration msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs_srvs::msg::PWMServoStateDuration>()
{
  return msgs_srvs::msg::builder::Init_PWMServoStateDuration_state();
}

}  // namespace msgs_srvs

#endif  // MSGS_SRVS__MSG__DETAIL__PWM_SERVO_STATE_DURATION__BUILDER_HPP_
