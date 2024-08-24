#ifndef __LIBSMI_LEDS_H__
#define __LIBSMI_LEDS_H__

#include <Python.h>

PyObject *smileds_leds_init(PyObject *self, PyObject *args);
PyObject *smileds_leds_brightness(PyObject *self, PyObject *args);
PyObject *smileds_leds_clear(PyObject *self, PyObject *args);
PyObject *smileds_leds_set(PyObject *self, PyObject *args);
PyObject *smileds_leds_send(PyObject *self, PyObject *args);

#endif
