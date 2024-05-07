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
void leds_clear();
void leds_set_pixel(uint8_t  channel, uint16_t  pixel, color_t color);
void leds_set(color_t *data);
void leds_send();

#ifdef __cplusplus
}
#endif

#endif
