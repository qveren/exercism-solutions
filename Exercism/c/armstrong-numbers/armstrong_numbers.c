#include "armstrong_numbers.h"
#include <stdbool.h>

bool is_armstrong_number(int candidate) 
{
    int count = 0;
    int original = candidate;
    int copy = candidate;
    for (; candidate > 0; count++) {
        candidate /= 10;
    }
    int digit = 0;
    int sum = 0;
    int result = 1;
    while (copy > 0) {
        digit = copy % 10;
        for (int i = 0; count > i; i++) {
            result *= digit;
        }
        sum += result;
        result = 1;
        copy /= 10;
    }
    if (sum == original) return true;
    return false;
}
