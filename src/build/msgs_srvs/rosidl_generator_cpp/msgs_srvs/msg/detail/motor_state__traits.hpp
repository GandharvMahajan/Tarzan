// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from msgs_srvs:msg/MotorState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__MOTOR_STATE__TRAITS_HPP_
#define MSGS_SRVS__MSG__DETAIL__MOTOR_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "msgs_srvs/msg/detail/motor_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace msgs_srvs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorState & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: rps
  {
    out << "rps: ";
    rosidl_generator_traits::value_to_yaml(msg.rps, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: rps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rps: ";
    rosidl_generator_traits::value_to_yaml(msg.rps, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace msgs_srvs

namespace rosidl_generator_traits
{

[[deprecated("use msgs_srvs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const msgs_srvs::msg::MotorState & msg,
  std::ostream & out, size_t indentation = 0)
{
  msgs_srvs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use msgs_srvs::msg::to_yaml() instead")]]
inline std::string to_yaml(const msgs_srvs::msg::MotorState & msg)
{
  return msgs_srvs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<msgs_srvs::msg::MotorState>()
{
  return "msgs_srvs::msg::MotorState";
}

template<>
inline const char * name<msgs_srvs::msg::MotorState>()
{
  return "msgs_srvs/msg/MotorState";
}

template<>
struct has_fixed_size<msgs_srvs::msg::MotorState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<msgs_srvs::msg::MotorState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<msgs_srvs::msg::MotorState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MSGS_SRVS__MSG__DETAIL__MOTOR_STATE__TRAITS_HPP_
