#include "pascals_triangle.h"
#include <stdlib.h>

uint8_t **create_triangle(size_t rows) {
    if (rows == 0) {
        uint8_t **triangle = malloc(sizeof(uint8_t *));
        if (!triangle) return NULL;
        triangle[0] = malloc(sizeof(uint8_t));
        if (!triangle[0]) {
            free(triangle);
            return NULL;
        }
        triangle[0][0] = 0;
        return triangle;
    }
    uint8_t **triangle = malloc(sizeof(uint8_t *) * rows);
    if (!triangle) return NULL;
    for (size_t i = 0; i < rows; ++i) {
        triangle[i] = calloc(rows, sizeof(uint8_t));
        if (triangle[i] == NULL) {
            free_triangle(triangle, i);
            return NULL;
        }
        for (size_t j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                triangle[i][j] = 1;
            }
            else {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]; 
            }
        }
    }
    return triangle;
}

void free_triangle(uint8_t **triangle, size_t rows) {
    for (size_t i = 0; i < rows; ++i) {
        if (triangle[i] != NULL)
            free(triangle[i]);  
    }
    free(triangle);
}
