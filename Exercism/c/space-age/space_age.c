#include "space_age.h"

const float ORBITAL[] = {
   0.2408467,
   0.61519726,
   1.0,
   1.8808158,
   11.862615,
   29.447498,
   84.016846,
   164.79132
};

float age(planet_t planet, int64_t seconds) 
{
    int64_t age_on_earth = seconds / 31557600.0f;
    if (planet < MERCURY || planet > NEPTUNE) return -1.0;

    float age_on_planet = age_on_earth / ORBITAL[planet];
    
    return age_on_planet;
}
