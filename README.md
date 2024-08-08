# rpi_smi_led
A fixed up, debugged version of rpi_smi_led

# Installation

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


# Building your own code

To build your own code, run:

```
gcc -I /usr/local/include -L /usr/local/lib my_test.c -lsmi_leds
```
