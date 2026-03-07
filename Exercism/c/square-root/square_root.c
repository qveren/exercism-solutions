#include "square_root.h"

unsigned int square_root(unsigned int x)
{
    unsigned int bit = 1 << 30, result = 0, remainder = x;
    while (bit > x) {
        bit >>= 2;
    }
    while (bit != 0) {
        if (remainder >= result + bit) {
            remainder -= (result + bit);
            result = (result >> 1) + bit;
            bit >>= 2;
        }
        else {
            bit >>= 2;
            result >>= 1;
        }
    }
    return result;
}
