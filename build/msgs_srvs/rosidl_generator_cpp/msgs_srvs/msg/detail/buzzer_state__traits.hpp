// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from msgs_srvs:msg/BuzzerState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__BUZZER_STATE__TRAITS_HPP_
#define MSGS_SRVS__MSG__DETAIL__BUZZER_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "msgs_srvs/msg/detail/buzzer_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace msgs_srvs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BuzzerState & msg,
  std::ostream & out)
{
  out << "{";
  // member: freq
  {
    out << "freq: ";
    rosidl_generator_traits::value_to_yaml(msg.freq, out);
    out << ", ";
  }

  // member: on_time
  {
    out << "on_time: ";
    rosidl_generator_traits::value_to_yaml(msg.on_time, out);
    out << ", ";
  }

  // member: off_time
  {
    out << "off_time: ";
    rosidl_generator_traits::value_to_yaml(msg.off_time, out);
    out << ", ";
  }

  // member: repeat
  {
    out << "repeat: ";
    rosidl_generator_traits::value_to_yaml(msg.repeat, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BuzzerState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: freq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "freq: ";
    rosidl_generator_traits::value_to_yaml(msg.freq, out);
    out << "\n";
  }

  // member: on_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "on_time: ";
    rosidl_generator_traits::value_to_yaml(msg.on_time, out);
    out << "\n";
  }

  // member: off_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "off_time: ";
    rosidl_generator_traits::value_to_yaml(msg.off_time, out);
    out << "\n";
  }

  // member: repeat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "repeat: ";
    rosidl_generator_traits::value_to_yaml(msg.repeat, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BuzzerState & msg, bool use_flow_style = false)
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
  const msgs_srvs::msg::BuzzerState & msg,
  std::ostream & out, size_t indentation = 0)
{
  msgs_srvs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use msgs_srvs::msg::to_yaml() instead")]]
inline std::string to_yaml(const msgs_srvs::msg::BuzzerState & msg)
{
  return msgs_srvs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<msgs_srvs::msg::BuzzerState>()
{
  return "msgs_srvs::msg::BuzzerState";
}

template<>
inline const char * name<msgs_srvs::msg::BuzzerState>()
{
  return "msgs_srvs/msg/BuzzerState";
}

template<>
struct has_fixed_size<msgs_srvs::msg::BuzzerState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<msgs_srvs::msg::BuzzerState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<msgs_srvs::msg::BuzzerState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MSGS_SRVS__MSG__DETAIL__BUZZER_STATE__TRAITS_HPP_
