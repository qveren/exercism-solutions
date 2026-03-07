#include "sieve.h"
#include <stdbool.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) 
{
    if (limit < 2) return 0;
    bool mass[limit];
    for (uint32_t i = 2; i <= limit; i++) {
        mass[i] = true;
    }
    for (uint32_t i = 2; i * i <= limit; i++) {
        if (mass[i]) {
            for (uint32_t j = i * i; j <= limit; j += i) {
                mass[j] = false;
            }
        }
    }
    size_t count = 0;
    for (uint32_t i = 2; i <= limit; i++) {
        if (mass[i]) {
            if (count < max_primes) {
                primes[count] = i;
                count++;
            }
        }
    }
    return count;
}
