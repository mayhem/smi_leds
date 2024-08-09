# smi_leds

This project allows you to drive 8 or 16 WS2812 LED strips with one single Raspberry Pi!

The basis for this project is Jeremy P Bentham's rpi_smi_leds project that uses the RPi's
SMI memory interface to accurately drive 8 or 16 LED strips -- flicker free and without
a lot of CPU overhead -- simply amazing. For all the gory details on how this works,
read Jeremy's excellent blog post about his code:

    https://iosoft.blog/category/neopixel/

However, Jeremy's code was just that -- some code, but with zero documentaion on how to
build it (several fixes were needed) or how to install it on a RPi. This project 
addresses those shortcomings and packages that code into a deployable project.

You can choose to link to a static C library build with CMake and include it in your
C/C++ project, or you can choose the python module, which can be installed from pip.

# Installation

## C/C++ static library

To install smi_leds for 8 LED strands:

```
mkdir build
cd build
cmake ..
make
sudo make install
```

To install for 16 channels, pass an option to cmake:

```
mkdir build
cd build
cmake .. -DENABLE_16_CHANNELS:BOOL=ON
make
sudo make install
```

### Building your own code

To build your own code, run:

```
gcc -I /usr/local/include -L /usr/local/lib my_test.c -lsmi_leds
```

## Python 

To install via pip for 8 LED strands:

```
pip install smi_leds
```

To install via pip for 16 LED strands:

```
export LED_NCHANS=16
pip install smi_leds
```

# Hardware Setup

![alt text](https://github.com/mayhem/smi_leds/blob/main/docs/rpi_smi_pinout.png?raw=true)


![alt text](https://github.com/mayhem/smi_leds/blob/main/docs/rpi_smi_pins-2.png?raw=true)
