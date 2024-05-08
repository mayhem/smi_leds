#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include "rpi_pixleds_lib.h"

#define NUM_LEDS 10
#define NUM_STRIPS 8

int main(int argc, char *argv[])
{
    bool    ret;
    uint8_t buffer[NUM_LEDS * NUM_STRIPS * 3];


    ret = leds_init(NUM_LEDS, 25);
    leds_clear();
    leds_send();

    for(int row = 0;; row++)
    {
//        memset(buffer, 0, sizeof(buffer));
        uint8_t *ptr = buffer;
        for(int led = 0; led < NUM_LEDS; led++)
        {
            for(int strip = 0; strip < NUM_STRIPS; strip++)
            {
                *(ptr++) = 0x00;
                *(ptr++) = 0x00;
                *(ptr++) = 0xFF;
            }
        }
//        for(int o = 0; o < 24; o++)
//            printf("%02X ", buffer[o]);
//        printf("\n");
        leds_set(buffer);
        leds_brightness(row % 101);
        leds_send();
        usleep(10000);
    }
}
