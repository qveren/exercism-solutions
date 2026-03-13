#include "spiral_matrix.h"
#include <stdlib.h>

spiral_matrix_t *spiral_matrix_create(int x) {

    spiral_matrix_t *result = malloc(sizeof(spiral_matrix_t));
    if (result == NULL) return NULL;

    result->size = x;

    result->matrix = malloc(x * sizeof(int *));
    if (result->matrix == NULL) {
        free(result); 
        return NULL;
    }
    
    if (x == 0) {
        result->matrix = NULL;
        result->size = 0;
        return result;
    }
    for (int i = 0; i < x; i++) {
        result->matrix[i] = malloc(x * sizeof(int));
        if (result->matrix[i] == NULL) {
            for (int j = i - 1; j >= 0; j--) {
                free(result->matrix[j]);
            }
            free(result->matrix);
            free(result);
            return NULL;
        }
    }


    int top = 0, bottom = x - 1;
    int left = 0, right = x - 1;
    int value = 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            result->matrix[top][i] = value++;
        }
        top++;
        for (int j = top; j <= bottom; j++) {
            result->matrix[j][right] = value++;
        }
        right--;
        if (top <= bottom) {
            for (int k = right; k >= left; k--) {
                result->matrix[bottom][k] = value++;
            }
        bottom--;
        }
        if (left <= right) {
            for (int z = bottom; z >= top; z--) {
                result->matrix[z][left] = value++;
            }
        left++;
        }
    }
    

    return result;
}
void spiral_matrix_destroy(spiral_matrix_t *result) 
{
    if (result == NULL) return;
    for (int i = 0; i < result->size; ++i) {
        free(result->matrix[i]);
    }
    free(result->matrix);
    free(result);
}
