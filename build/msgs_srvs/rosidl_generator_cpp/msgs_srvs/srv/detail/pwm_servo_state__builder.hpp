// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs_srvs:srv/PWMServoState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__SRV__DETAIL__PWM_SERVO_STATE__BUILDER_HPP_
#define MSGS_SRVS__SRV__DETAIL__PWM_SERVO_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs_srvs/srv/detail/pwm_servo_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs_srvs
{

namespace srv
{

namespace builder
{

class Init_PWMServoState_Request_cmd
{
public:
  Init_PWMServoState_Request_cmd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::msgs_srvs::srv::PWMServoState_Request cmd(::msgs_srvs::srv::PWMServoState_Request::_cmd_type arg)
  {
    msg_.cmd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs_srvs::srv::PWMServoState_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs_srvs::srv::PWMServoState_Request>()
{
  return msgs_srvs::srv::builder::Init_PWMServoState_Request_cmd();
}

}  // namespace msgs_srvs


namespace msgs_srvs
{

namespace srv
{

namespace builder
{

class Init_PWMServoState_Response_state
{
public:
  explicit Init_PWMServoState_Response_state(::msgs_srvs::srv::PWMServoState_Response & msg)
  : msg_(msg)
  {}
  ::msgs_srvs::srv::PWMServoState_Response state(::msgs_srvs::srv::PWMServoState_Response::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs_srvs::srv::PWMServoState_Response msg_;
};

class Init_PWMServoState_Response_success
{
public:
  Init_PWMServoState_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PWMServoState_Response_state success(::msgs_srvs::srv::PWMServoState_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_PWMServoState_Response_state(msg_);
  }

private:
  ::msgs_srvs::srv::PWMServoState_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs_srvs::srv::PWMServoState_Response>()
{
  return msgs_srvs::srv::builder::Init_PWMServoState_Response_success();
}

}  // namespace msgs_srvs

#endif  // MSGS_SRVS__SRV__DETAIL__PWM_SERVO_STATE__BUILDER_HPP_
