#ifndef __LIBSMI_LEDS_H__
#define __LIBSMI_LEDS_H__

#include <Python.h>

PyObject *smi_leds_leds_init(PyObject *self, PyObject *args);
PyObject *smi_leds_leds_brightness(PyObject *self, PyObject *args);
PyObject *smi_leds_leds_clear(PyObject *self, PyObject *args);
PyObject *smi_leds_leds_set(PyObject *self, PyObject *args);
PyObject *smi_leds_leds_send(PyObject *self, PyObject *args);

#endif
