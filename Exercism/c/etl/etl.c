#include "etl.h"
#include <stdlib.h>
#include <ctype.h>

int compare_new_maps(const void *a, const void *b) {
    const new_map *map_a = (const new_map *)a;
    const new_map *map_b = (const new_map *)b;
    return (map_a->key - map_b->key);
}

int convert(const legacy_map *input, const size_t input_len, new_map **output) {
    size_t total = 0;
    for (size_t i = 0; i < input_len; ++i) {
        for (int j = 0; input[i].keys[j] != '\0'; ++j) {
            total++;
        }
    }
    if (total == 0) return 0;
    new_map *array = calloc(total, sizeof(new_map));

    size_t count = 0;
    for (size_t i = 0; i < input_len; i++) {
        for (size_t j = 0; input[i].keys[j] != '\0'; j++) {
            array[count].key = tolower(input[i].keys[j]);
            array[count].value = input[i].value;
            count++;
        }   
    }
    qsort(array, total, sizeof(new_map), compare_new_maps);
    *output = array;
    return total;
}