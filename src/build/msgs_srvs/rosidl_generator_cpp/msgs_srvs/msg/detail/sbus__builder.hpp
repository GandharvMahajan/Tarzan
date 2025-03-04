// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs_srvs:msg/Sbus.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__SBUS__BUILDER_HPP_
#define MSGS_SRVS__MSG__DETAIL__SBUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs_srvs/msg/detail/sbus__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs_srvs
{

namespace msg
{

namespace builder
{

class Init_Sbus_channel
{
public:
  explicit Init_Sbus_channel(::msgs_srvs::msg::Sbus & msg)
  : msg_(msg)
  {}
  ::msgs_srvs::msg::Sbus channel(::msgs_srvs::msg::Sbus::_channel_type arg)
  {
    msg_.channel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs_srvs::msg::Sbus msg_;
};

class Init_Sbus_header
{
public:
  Init_Sbus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Sbus_channel header(::msgs_srvs::msg::Sbus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Sbus_channel(msg_);
  }

private:
  ::msgs_srvs::msg::Sbus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs_srvs::msg::Sbus>()
{
  return msgs_srvs::msg::builder::Init_Sbus_header();
}

}  // namespace msgs_srvs

#endif  // MSGS_SRVS__MSG__DETAIL__SBUS__BUILDER_HPP_
