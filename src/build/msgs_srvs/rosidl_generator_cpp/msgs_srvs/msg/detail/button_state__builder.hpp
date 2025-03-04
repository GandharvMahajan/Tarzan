// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs_srvs:msg/ButtonState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__BUTTON_STATE__BUILDER_HPP_
#define MSGS_SRVS__MSG__DETAIL__BUTTON_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs_srvs/msg/detail/button_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs_srvs
{

namespace msg
{

namespace builder
{

class Init_ButtonState_state
{
public:
  explicit Init_ButtonState_state(::msgs_srvs::msg::ButtonState & msg)
  : msg_(msg)
  {}
  ::msgs_srvs::msg::ButtonState state(::msgs_srvs::msg::ButtonState::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs_srvs::msg::ButtonState msg_;
};

class Init_ButtonState_id
{
public:
  Init_ButtonState_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ButtonState_state id(::msgs_srvs::msg::ButtonState::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_ButtonState_state(msg_);
  }

private:
  ::msgs_srvs::msg::ButtonState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs_srvs::msg::ButtonState>()
{
  return msgs_srvs::msg::builder::Init_ButtonState_id();
}

}  // namespace msgs_srvs

#endif  // MSGS_SRVS__MSG__DETAIL__BUTTON_STATE__BUILDER_HPP_
