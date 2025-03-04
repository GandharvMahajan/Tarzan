// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from msgs_srvs:msg/LedState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__LED_STATE__TRAITS_HPP_
#define MSGS_SRVS__MSG__DETAIL__LED_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "msgs_srvs/msg/detail/led_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace msgs_srvs
{

namespace msg
{

inline void to_flow_style_yaml(
  const LedState & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
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
  const LedState & msg,
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

inline std::string to_yaml(const LedState & msg, bool use_flow_style = false)
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
  const msgs_srvs::msg::LedState & msg,
  std::ostream & out, size_t indentation = 0)
{
  msgs_srvs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use msgs_srvs::msg::to_yaml() instead")]]
inline std::string to_yaml(const msgs_srvs::msg::LedState & msg)
{
  return msgs_srvs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<msgs_srvs::msg::LedState>()
{
  return "msgs_srvs::msg::LedState";
}

template<>
inline const char * name<msgs_srvs::msg::LedState>()
{
  return "msgs_srvs/msg/LedState";
}

template<>
struct has_fixed_size<msgs_srvs::msg::LedState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<msgs_srvs::msg::LedState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<msgs_srvs::msg::LedState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MSGS_SRVS__MSG__DETAIL__LED_STATE__TRAITS_HPP_
