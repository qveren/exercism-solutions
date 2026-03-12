#include "kindergarten_garden.h"
#include <string.h>

plant_t transform_letter(char letter) 
{ 
    if (letter == 'C') return CLOVER;
    if (letter == 'G') return GRASS;
    if (letter == 'R') return RADISHES;
    if (letter == 'V') return VIOLETS;
    else return 0;
}

plants_t plants(const char diagram[4], const char* student)
{
    int index = student[0] - 'A';
    const char *second_row = strchr(diagram, '\n') + 1;  
    plants_t result;
    result.plants[0] = transform_letter(diagram[index*2]);
    result.plants[1] = transform_letter(diagram[index*2+1]);
    result.plants[2] = transform_letter(second_row[index*2]);
    result.plants[3] = transform_letter(second_row[index*2+1]);
    return result;
}
