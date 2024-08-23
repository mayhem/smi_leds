#ifndef RPI_WS281X_SMI_SMILEDS_H
#define RPI_WS281X_SMI_SMILEDS_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct {
    uint8_t b;
    uint8_t r;
    uint8_t g;
    uint8_t a;
} color_t;

bool leds_init(int init_led_count, uint8_t brightness); // 0 - 100 brightness
void leds_brightness(uint8_t brightness); // 0 - 100
void leds_clear();
void leds_set_pixel(uint8_t  channel, uint16_t  pixel, color_t color);
void leds_set(uint8_t *data);
void leds_send(void);

#ifdef __cplusplus
}
#endif

#endif
