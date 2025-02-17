// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs_srvs:msg/BuzzerState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__BUZZER_STATE__BUILDER_HPP_
#define MSGS_SRVS__MSG__DETAIL__BUZZER_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs_srvs/msg/detail/buzzer_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs_srvs
{

namespace msg
{

namespace builder
{

class Init_BuzzerState_repeat
{
public:
  explicit Init_BuzzerState_repeat(::msgs_srvs::msg::BuzzerState & msg)
  : msg_(msg)
  {}
  ::msgs_srvs::msg::BuzzerState repeat(::msgs_srvs::msg::BuzzerState::_repeat_type arg)
  {
    msg_.repeat = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs_srvs::msg::BuzzerState msg_;
};

class Init_BuzzerState_off_time
{
public:
  explicit Init_BuzzerState_off_time(::msgs_srvs::msg::BuzzerState & msg)
  : msg_(msg)
  {}
  Init_BuzzerState_repeat off_time(::msgs_srvs::msg::BuzzerState::_off_time_type arg)
  {
    msg_.off_time = std::move(arg);
    return Init_BuzzerState_repeat(msg_);
  }

private:
  ::msgs_srvs::msg::BuzzerState msg_;
};

class Init_BuzzerState_on_time
{
public:
  explicit Init_BuzzerState_on_time(::msgs_srvs::msg::BuzzerState & msg)
  : msg_(msg)
  {}
  Init_BuzzerState_off_time on_time(::msgs_srvs::msg::BuzzerState::_on_time_type arg)
  {
    msg_.on_time = std::move(arg);
    return Init_BuzzerState_off_time(msg_);
  }

private:
  ::msgs_srvs::msg::BuzzerState msg_;
};

class Init_BuzzerState_freq
{
public:
  Init_BuzzerState_freq()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BuzzerState_on_time freq(::msgs_srvs::msg::BuzzerState::_freq_type arg)
  {
    msg_.freq = std::move(arg);
    return Init_BuzzerState_on_time(msg_);
  }

private:
  ::msgs_srvs::msg::BuzzerState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs_srvs::msg::BuzzerState>()
{
  return msgs_srvs::msg::builder::Init_BuzzerState_freq();
}

}  // namespace msgs_srvs

#endif  // MSGS_SRVS__MSG__DETAIL__BUZZER_STATE__BUILDER_HPP_
