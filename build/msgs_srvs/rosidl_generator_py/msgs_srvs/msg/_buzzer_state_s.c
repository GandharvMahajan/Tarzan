// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from msgs_srvs:msg/BuzzerState.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "msgs_srvs/msg/detail/buzzer_state__struct.h"
#include "msgs_srvs/msg/detail/buzzer_state__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool msgs_srvs__msg__buzzer_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("msgs_srvs.msg._buzzer_state.BuzzerState", full_classname_dest, 39) == 0);
  }
  msgs_srvs__msg__BuzzerState * ros_message = _ros_message;
  {  // freq
    PyObject * field = PyObject_GetAttrString(_pymsg, "freq");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->freq = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // on_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "on_time");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->on_time = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // off_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "off_time");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->off_time = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // repeat
    PyObject * field = PyObject_GetAttrString(_pymsg, "repeat");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->repeat = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * msgs_srvs__msg__buzzer_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BuzzerState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("msgs_srvs.msg._buzzer_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BuzzerState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  msgs_srvs__msg__BuzzerState * ros_message = (msgs_srvs__msg__BuzzerState *)raw_ros_message;
  {  // freq
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->freq);
    {
      int rc = PyObject_SetAttrString(_pymessage, "freq", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // on_time
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->on_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "on_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // off_time
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->off_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "off_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // repeat
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->repeat);
    {
      int rc = PyObject_SetAttrString(_pymessage, "repeat", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
