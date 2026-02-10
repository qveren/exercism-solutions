#include "leap.h"
#include <stdbool.h>
#include <stddef.h>

bool leap_year(int year)
{
    if (year == '\0') return NULL;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)) return true;
    return false;
}
