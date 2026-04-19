#include "pythagorean_triplet.h"
#include <stdlib.h>
#include <stdint.h>

triplets_t *triplets_with_sum(int sum) {
    int count = 0;
    for (uint16_t a = 1; a < sum / 3; a++) {
        for (uint16_t b = a + 1; b < sum / 2; b++) {
            int c = sum - a - b;
            if (a*a + b*b == c*c) {
                count++;
            }
        }
    }
    triplets_t *result = malloc(sizeof(triplets_t) + sizeof(triplet_t) * count);
    if (!result) return NULL;
    result->count = count;

    size_t idx = 0;
    for (uint16_t a = 1; a < sum / 3; a++) {
        for (uint16_t b = a + 1; b < sum / 2; b++) {
            int c = sum - a - b;
            if (a*a + b*b == c*c) {
                result->triplets[idx].a = a;
                result->triplets[idx].b = b;
                result->triplets[idx].c = c;
                idx++;
            }
        }
    }
    return result;
}
void free_triplets(triplets_t *triplets) {
    free(triplets);
}