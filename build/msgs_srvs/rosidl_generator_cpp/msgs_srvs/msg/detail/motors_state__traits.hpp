// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from msgs_srvs:msg/MotorsState.idl
// generated code does not contain a copyright notice

#ifndef MSGS_SRVS__MSG__DETAIL__MOTORS_STATE__TRAITS_HPP_
#define MSGS_SRVS__MSG__DETAIL__MOTORS_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "msgs_srvs/msg/detail/motors_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'data'
#include "msgs_srvs/msg/detail/motor_state__traits.hpp"

namespace msgs_srvs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorsState & msg,
  std::ostream & out)
{
  out << "{";
  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorsState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorsState & msg, bool use_flow_style = false)
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
  const msgs_srvs::msg::MotorsState & msg,
  std::ostream & out, size_t indentation = 0)
{
  msgs_srvs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use msgs_srvs::msg::to_yaml() instead")]]
inline std::string to_yaml(const msgs_srvs::msg::MotorsState & msg)
{
  return msgs_srvs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<msgs_srvs::msg::MotorsState>()
{
  return "msgs_srvs::msg::MotorsState";
}

template<>
inline const char * name<msgs_srvs::msg::MotorsState>()
{
  return "msgs_srvs/msg/MotorsState";
}

template<>
struct has_fixed_size<msgs_srvs::msg::MotorsState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<msgs_srvs::msg::MotorsState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<msgs_srvs::msg::MotorsState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MSGS_SRVS__MSG__DETAIL__MOTORS_STATE__TRAITS_HPP_
