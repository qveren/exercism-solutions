#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit) 
{
    unsigned sum = 0;
    for (size_t i = 0; i < limit; i++) {
        for (size_t j = 0; j < number_of_factors; j++) {
            if (factors[j] != 0 && i % factors[j] == 0) {
                sum += i;
                break;
            }
        }
    }
    return sum;
}
