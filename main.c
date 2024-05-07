#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include "rpi_pixleds_lib.h"

#define NUM_LEDS 10
#define NUM_STRIPS 8

int main(int argc, char *argv[])
{
    bool  ret;
    int   buffer[NUM_LEDS * NUM_STRIPS];

    printf("buf: %d\n", sizeof(buffer));

    ret = leds_init(NUM_LEDS, 25);
    leds_clear();
    leds_send();

    for(int row = 0;; row++)
    {
        memset(buffer, 0, sizeof(int) * NUM_LEDS * NUM_STRIPS);
        for(int led = 0; led < NUM_LEDS; led++)
        {
            for(int strip = 0; strip < NUM_STRIPS; strip++)
            {
                int *ptr = &buffer[strip * NUM_LEDS + led];
                *(ptr++) = 0xFFFFFF;
            }
        }
        printf("row: %d\n", row);
        leds_set((color_t *)buffer);
        leds_brightness(row % 101);
        leds_send();
        usleep(10000);
    }
}
