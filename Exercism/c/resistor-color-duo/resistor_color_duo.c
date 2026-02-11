#include "resistor_color_duo.h"
#include <stdlib.h>


uint16_t color_code(resistor_band_t *colors)
{
    uint16_t two_colors = colors[0] * 10 + colors[1];
    return two_colors;
}

