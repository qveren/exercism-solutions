#include "square_root.h"

unsigned int square_root(unsigned int x)
{
    unsigned int low = 1, high = x;
    unsigned int mid = (low + high) / 2;
    for (unsigned int i = 0; i < x; i++) {
        if ((mid * mid) >= x) {
            high = mid + 1;
        }
        else if ((mid * mid) <= x) {
            low = mid;
        }
        else if ((mid * mid) == x){
            return mid;
        }
        mid = (low + high) / 2;
    }
    return mid;
}
