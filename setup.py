#!/usr/bin/env python3

from setuptools import setup, Extension

setup(name = "smi_leds",
      version = "1.0",
      ext_modules = [Extension("smi_leds", ["module.c", "libsmi_leds.c", "rpi_pixleds_lib.c", "rpi_dma_utils.c"])]
)
