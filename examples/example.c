#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include "smi_leds.h"

#define NUM_LEDS 8
#define NUM_STRIPS 8

int main(int argc, char *argv[])
{
    bool    ret;
    uint8_t buffer[NUM_LEDS * NUM_STRIPS * 3];
    uint8_t *ptr = buffer;

    // TODO: Check the num leds setting
    // initialize the smi_leds module, starting with a 25% brightness
    leds_init(NUM_LEDS, 25);

    // Manually and slowly build the color buffer. 3 bytes per pixel (RGB)
    // for NUM_LEDS pixels and NUM_STRIPS strips
    for(int led = 0; led < NUM_LEDS; led++)
    {
        for(int strip = 0; strip < NUM_STRIPS; strip++)
        {
            *(ptr++) = 0x00;
            *(ptr++) = 0x00;
            *(ptr++) = 0xFF;
        }
    }

    // Send the buffer to the SMI buffer
    leds_set(buffer);

    // Actually send them to the LEDs:
    leds_send();
}
