// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs_srvs:msg/LedState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__LED_STATE__BUILDER_HPP_
#define MSGS_SRVS__MSG__DETAIL__LED_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs_srvs/msg/detail/led_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs_srvs
{

namespace msg
{

namespace builder
{

class Init_LedState_repeat
{
public:
  explicit Init_LedState_repeat(::msgs_srvs::msg::LedState & msg)
  : msg_(msg)
  {}
  ::msgs_srvs::msg::LedState repeat(::msgs_srvs::msg::LedState::_repeat_type arg)
  {
    msg_.repeat = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs_srvs::msg::LedState msg_;
};

class Init_LedState_off_time
{
public:
  explicit Init_LedState_off_time(::msgs_srvs::msg::LedState & msg)
  : msg_(msg)
  {}
  Init_LedState_repeat off_time(::msgs_srvs::msg::LedState::_off_time_type arg)
  {
    msg_.off_time = std::move(arg);
    return Init_LedState_repeat(msg_);
  }

private:
  ::msgs_srvs::msg::LedState msg_;
};

class Init_LedState_on_time
{
public:
  explicit Init_LedState_on_time(::msgs_srvs::msg::LedState & msg)
  : msg_(msg)
  {}
  Init_LedState_off_time on_time(::msgs_srvs::msg::LedState::_on_time_type arg)
  {
    msg_.on_time = std::move(arg);
    return Init_LedState_off_time(msg_);
  }

private:
  ::msgs_srvs::msg::LedState msg_;
};

class Init_LedState_id
{
public:
  Init_LedState_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LedState_on_time id(::msgs_srvs::msg::LedState::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_LedState_on_time(msg_);
  }

private:
  ::msgs_srvs::msg::LedState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs_srvs::msg::LedState>()
{
  return msgs_srvs::msg::builder::Init_LedState_id();
}

}  // namespace msgs_srvs

#endif  // MSGS_SRVS__MSG__DETAIL__LED_STATE__BUILDER_HPP_
