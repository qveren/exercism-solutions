#include "resistor_color_trio.h"
#include <stdint.h>
#include <stddef.h>
resistor_value_t color_code(resistor_band_t *colors)
{
    if (colors[0] == 0 && colors[1] == 0 && colors[2] == 0) {
        resistor_value_t empty_result = {0, OHMS};
        return empty_result;
    }

    resistor_value_t result;
    uint64_t total;

    total = colors[0] * 10 + colors[1];
    for (resistor_band_t i = 0; i < colors[2]; i++) {
        total *= 10;
    }

    if (total % 1000000000ULL == 0) {
        total /= 1000000000ULL;
        result.value = total;
        result.unit = GIGAOHMS;
        return result;
    }
    else if (total % 1000000ULL == 0) {
        total /= 1000000ULL;
        result.value = total;
        result.unit = MEGAOHMS;
        return result;
    }
    else if (total % 1000ULL == 0) {
        total /= 1000ULL;
        result.value = total;
        result.unit = KILOOHMS;
        return result;
    }
    else {
        result.value = total;
        result.unit = OHMS;
        return result;
    }
}

