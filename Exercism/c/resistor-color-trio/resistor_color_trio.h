#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H
#include <stdint.h>

typedef enum {
    BLACK, BROWN, RED, ORANGE, YELLOW,
    GREEN, BLUE, VIOLET, GREY, WHITE
} resistor_band_t;

typedef enum {
    OHMS, KILOOHMS, MEGAOHMS, GIGAOHMS
} res_unit_t;

typedef struct {
    uint64_t value;
    res_unit_t unit;
} resistor_value_t;


resistor_value_t color_code(resistor_band_t *colors);
const resistor_band_t *colors(void);


#endif
