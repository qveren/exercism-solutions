#include "all_your_base.h"
#include <string.h>

size_t rebase(int8_t digits[64], int16_t input_base, int16_t output_base, size_t input_length)
{
    if (input_base < 2 || output_base < 2 || input_length < 1) return 0;
    int64_t value = 0;
    for (size_t i = 0; i < input_length; ++i) {
        if (digits[i] >= input_base || digits[i] < 0) {
            return 0;
        }
        value = (value * input_base) + digits[i];
    }
    int64_t i = 0;
    do {
        digits[i] = value % output_base;
        value = value / output_base;
        ++i;
    } while (value > 0);
    for (size_t start = 0, end = i - 1; start < end; start++, end--) { 
        size_t tmp = digits[start];
        digits[start] = digits[end];
        digits[end] = tmp;
    }
    return i;
}
