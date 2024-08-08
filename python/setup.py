#!/usr/bin/env python3

import os
import pathlib
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext as build_ext_orig

class CMakeExtension(Extension):
    def __init__(self, name):
        # don't invoke the original build_ext for this special extension
        super().__init__(name, sources=[])

class build_ext(build_ext_orig):
    def run(self):
        for ext in self.extensions:
            self.build_cmake(ext)
        super().run()

    def build_cmake(self, ext):
        cwd = pathlib.Path().absolute()
        cmake_dir = os.path.join(cwd, "..")

        # these dirs will be created in build_py, so if you don't have
        # any python sources to bundle, the dirs will be missing
        build_temp = pathlib.Path(self.build_temp)
        build_temp.mkdir(parents=True, exist_ok=True)
        extdir = pathlib.Path(self.get_ext_fullpath(ext.name))
        extdir.mkdir(parents=True, exist_ok=True)
        
        # example of cmake args
        config = 'Debug' if self.debug else 'Release'
        cmake_args = [
            '-DCMAKE_LIBRARY_OUTPUT_DIRECTORY='+str(extdir.parent.absolute()),
            '-DCMAKE_BUILD_TYPE=' + config,
            '-DBUILD_PYTHON_MODULE=ON',
            '-DBUILD_FORTRAN_LIBRARY=OFf',
            '-DBUILD_THE_EXAMPLES=OFF',
        ]
        
        # example of build args
        build_args = [
            '--config', config, 
        ]
        
        os.chdir(str(build_temp))
        self.spawn(['cmake', str(cmake_dir)] + cmake_args)
        if not self.dry_run:
            self.spawn(['cmake', '--build', '.'] + build_args)
        # Troubleshooting: if fail on line above then delete all possible 
        # temporary CMake files including "CMakeCache.txt" in top level dir.
        os.chdir(str(cwd))

setup(name = "smi_leds",
      version = "1.0",
#      ext_modules = [Extension("smi_leds",
#                               ["module.c", "libsmi_leds.c"],
#                               libraries=["smi_leds"],
#                               library_dirs=["/usr/local/lib"])],
      install_requires=[ 'wheel' ],
      ext_modules=[CMakeExtension('mypythonlibrary/myfortranlibrary')],
      cmdclass={'build_ext': build_ext,}
)
