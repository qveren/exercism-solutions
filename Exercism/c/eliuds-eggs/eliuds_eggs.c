#include "eliuds_eggs.h"

unsigned int egg_count(unsigned int num)
{   
    unsigned int count = 0;
    while (num > 0) {
    num = num & (num - 1);
    count++;
    }
    return count;
}
