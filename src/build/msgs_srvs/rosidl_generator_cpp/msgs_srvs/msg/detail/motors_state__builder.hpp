// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs_srvs:msg/MotorsState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__MOTORS_STATE__BUILDER_HPP_
#define MSGS_SRVS__MSG__DETAIL__MOTORS_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs_srvs/msg/detail/motors_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs_srvs
{

namespace msg
{

namespace builder
{

class Init_MotorsState_data
{
public:
  Init_MotorsState_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::msgs_srvs::msg::MotorsState data(::msgs_srvs::msg::MotorsState::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs_srvs::msg::MotorsState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs_srvs::msg::MotorsState>()
{
  return msgs_srvs::msg::builder::Init_MotorsState_data();
}

}  // namespace msgs_srvs

#endif  // MSGS_SRVS__MSG__DETAIL__MOTORS_STATE__BUILDER_HPP_
