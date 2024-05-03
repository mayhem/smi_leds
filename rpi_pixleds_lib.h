#ifndef RPI_WS281X_SMI_SMILEDS_H
#define RPI_WS281X_SMI_SMILEDS_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint8_t b;
    uint8_t r;
    uint8_t g;
    uint8_t a;
} color_t;


#ifdef __cplusplus
extern "C"
{
#endif


bool leds_init(int init_led_count);
void leds_set_pixel(uint8_t  channel, uint16_t  pixel, color_t color);
void leds_send();
void leds_set(int *buffer);
void leds_clear();

#ifdef __cplusplus
}
#endif

#endif
