#include "libsmi_leds.h"

char smi_leds_docs[] = "Drive up to 8 or 16 LED strips with one RPi.";

PyMethodDef smi_leds_funcs[] = 
{
	{
        "leds_init",
		(PyCFunction)smi_leds_leds_init,
		METH_VARARGS,
		smi_leds_docs
    },
	{
        "leds_brightness",
		(PyCFunction)smi_leds_leds_brightness,
		METH_VARARGS,
		smi_leds_docs
    },
	{
        "leds_clear",
		(PyCFunction)smi_leds_leds_clear,
		METH_NOARGS,
		smi_leds_docs
    },
	{
        "leds_set",
		(PyCFunction)smi_leds_leds_set,
		METH_VARARGS,
		smi_leds_docs
    },
	{
        "leds_send",
		(PyCFunction)smi_leds_leds_send,
		METH_NOARGS,
		smi_leds_docs
    },
    { NULL}
};

char smi_leds_mod_docs[] = "The SMI LEDs module.";

PyModuleDef smi_leds_mod = {
	PyModuleDef_HEAD_INIT,
	"smi_leds",
	smi_leds_mod_docs,
	-1,
	smi_leds_funcs,
	NULL,
	NULL,
	NULL,
	NULL
};

PyMODINIT_FUNC PyInit_smi_leds(void) {
	return PyModule_Create(&smi_leds_mod);
}
