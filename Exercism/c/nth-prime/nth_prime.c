#include "nth_prime.h"
#include <stdbool.h>

bool is_prime(uint32_t n)
{
    if (n < 2) return false;
    for (uint32_t i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

uint32_t nth(uint32_t n)
{
    uint32_t count = 0;
    uint32_t candidate = 0;
    while (count != n) {
        candidate++;
        if (is_prime(candidate)) {
            ++count;
        }
    }
    return candidate;
}
