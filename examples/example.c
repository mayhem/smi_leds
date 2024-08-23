#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<unistd.h>

#include "smi_leds.h"

#define NUM_LEDS 8
#define NUM_STRIPS 8

void hsv_to_rgb(float h, float s, float v, float *r, float *g, float *b) 
{
    int i = floor(h * 6);
    float f = h * 6 - i;
    float p = v * (1 - s);
    float q = v * (1 - f * s);
    float t = v * (1 - (1 - f) * s);

    switch (i % 6)
    {
        case 0: *r = v, *g = t, *b = p; break;
        case 1: *r = q, *g = v, *b = p; break;
        case 2: *r = p, *g = v, *b = t; break;
        case 3: *r = p, *g = q, *b = v; break;
        case 4: *r = t, *g = p, *b = v; break;
        case 5: *r = v, *g = p, *b = q; break;
    }
}

int main(int argc, char *argv[])
{
    uint8_t buffer[NUM_LEDS * NUM_STRIPS * 3];
    uint8_t *ptr;

    // TODO: Check the num leds setting
    // initialize the smi_leds module, starting with a 25% brightness
    leds_init(NUM_LEDS, 10);

    for(float t = 0.0;; t += .01)
    {
        // Manually and slowly build the color buffer. 3 bytes per pixel (RGB)
        // for NUM_LEDS pixels and NUM_STRIPS strips
        ptr = buffer;
        for(int strip = 0; strip < NUM_STRIPS; strip++)
        {
            float hue = fmod(t + (strip * .04), 1.0);
            float r, g, b;

            hsv_to_rgb(hue, 1.0, 1.0, &r, &g, &b);
            for(int led = 0; led < NUM_LEDS; led++)
            {
                *(ptr++) = (int)(r * 255);
                *(ptr++) = (int)(g * 255);
                *(ptr++) = (int)(b * 255);
            }
        }

        // Send the buffer to the SMI buffer
        leds_set(buffer);

        // Actually send them to the LEDs:
        leds_send();

        // Sleep for a while
        usleep(50000);
    }
}
