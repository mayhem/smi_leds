#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

#include "rpi_pixleds_lib.h"

#define NUM_LEDS 144
#define NUM_STRIPS 8

int main(int argc, char *argv[])
{
    bool  ret;
    int   buffer[NUM_LEDS * NUM_STRIPS];

    ret = leds_init(NUM_LEDS);

    leds_clear();
    leds_send();
    for(int row = 0; ; row++)
    {
        int *ptr = buffer;
        for(int strip = 0; strip < NUM_STRIPS; strip++)
        {
            for(int leds = 0; leds < NUM_LEDS; leds++)
                *(ptr++) = ((row % 64) << 16) | (row % 64);
        }
        leds_set(buffer);
        leds_send();
        usleep(10000);
    }
}
