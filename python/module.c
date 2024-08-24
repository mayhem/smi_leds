#include "libsmi_leds.h"

char smileds_docs[] = "Drive up to 8 or 16 LED strips with one RPi.";

PyMethodDef smileds_funcs[] = 
{
	{
        "leds_init",
		(PyCFunction)smileds_leds_init,
		METH_VARARGS,
		smileds_docs
    },
	{
        "leds_brightness",
		(PyCFunction)smileds_leds_brightness,
		METH_VARARGS,
		smileds_docs
    },
	{
        "leds_clear",
		(PyCFunction)smileds_leds_clear,
		METH_NOARGS,
		smileds_docs
    },
	{
        "leds_set",
		(PyCFunction)smileds_leds_set,
		METH_VARARGS,
		smileds_docs
    },
	{
        "leds_send",
		(PyCFunction)smileds_leds_send,
		METH_NOARGS,
		smileds_docs
    },
    { NULL}
};

char smileds_mod_docs[] = "The SMI LEDs module.";

PyModuleDef smileds_mod = {
	PyModuleDef_HEAD_INIT,
	"smileds",
	smileds_mod_docs,
	-1,
	smileds_funcs,
	NULL,
	NULL,
	NULL,
	NULL
};

PyMODINIT_FUNC PyInit_smileds(void) {
	return PyModule_Create(&smileds_mod);
}
