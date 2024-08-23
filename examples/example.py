#!/usr/bin/env python3

from time import sleep
import smi_leds

num_leds = 144 
num_strips = 8
total_leds = num_leds * num_strips
total_bytes = total_leds * 4


def set_led(leds, strip, index, color):
    offset = (strip * num_leds + index) * 4;
    leds[offset] = color[2]
    leds[offset + 1] = color[1]
    leds[offset + 2] = color[0]


smi_leds.leds_init(num_leds, 50)
smi_leds.leds_clear()

leds = bytearray((0,) * num_leds * num_strips * 4)
row = 0
while True:
    for strip in range(num_strips):
        for led in range(num_leds):
            if led // 4 % 2 == row % 2:
                color = ( 16, 0, 0 )
            else:
                color = ( 0, 0, 16 )
            set_led(leds, strip, led, color)

    smi_leds.leds_set(leds)
    smi_leds.leds_send()
    row += 1

sleep(1)

