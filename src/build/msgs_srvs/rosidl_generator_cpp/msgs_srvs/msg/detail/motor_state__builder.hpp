// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs_srvs:msg/MotorState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_
#define MSGS_SRVS__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs_srvs/msg/detail/motor_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs_srvs
{

namespace msg
{

namespace builder
{

class Init_MotorState_rps
{
public:
  explicit Init_MotorState_rps(::msgs_srvs::msg::MotorState & msg)
  : msg_(msg)
  {}
  ::msgs_srvs::msg::MotorState rps(::msgs_srvs::msg::MotorState::_rps_type arg)
  {
    msg_.rps = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs_srvs::msg::MotorState msg_;
};

class Init_MotorState_id
{
public:
  Init_MotorState_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorState_rps id(::msgs_srvs::msg::MotorState::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_MotorState_rps(msg_);
  }

private:
  ::msgs_srvs::msg::MotorState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs_srvs::msg::MotorState>()
{
  return msgs_srvs::msg::builder::Init_MotorState_id();
}

}  // namespace msgs_srvs

#endif  // MSGS_SRVS__MSG__DETAIL__MOTOR_STATE__BUILDER_HPP_
