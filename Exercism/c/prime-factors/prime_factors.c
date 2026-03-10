#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[MAXFACTORS])
{
    size_t count = 0;
    while (n % 2 == 0) {
        factors[count] = 2;
        n /= 2;
        count++;
    }
    uint64_t i = 3;
    for (;i * i <= n; i+=2) {
        while (n % i == 0) {
            factors[count] = i;
            n /= i;
            count++;
        }        
    }

    if (n > 1) {
        factors[count] = n;
        count++;
    }
    return count;
}
