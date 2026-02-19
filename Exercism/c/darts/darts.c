#include "darts.h"
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t score(coordinate_t position)
{
    coordinate_t pos = position;
    float distance = hypot(pos.x, pos.y);
    if (distance <= 1.0F) return 10;
    if (distance <= 5.0F) return 5;
    if (distance <= 10.0F) return 1;
    return 0;    
}
