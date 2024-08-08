#!/usr/bin/env python3

import sys
from setuptools import setup, Extension
from subprocess import check_output

def get_compile_flags():
    try:
        flags = check_output(["../detect_rpi.py"])
    except CalledProcessError:
        print("Cannot determine RPi version. Is this running on an RPi?")
        sys.exit(-1)

    print(flags)

    return flags


compile_flags = str(get_compile_flags(), "utf-8").split(" ")
print(compile_flags)
compile_flags.append("-DLED_NCHANS=8")

setup(name = "smi_leds",
      version = "1.0",
      ext_modules = [Extension("smi_leds",
                               ["module.c",
                               "libsmi_leds.c",
                               "../smi_led/rpi_dma_utils.c",
                               "../smi_led/rpi_pixleds_lib.c"],
                               extra_compile_args=compile_flags,
                               include_dirs=["../include"])],
      install_requires=[ 'wheel' ]
)
