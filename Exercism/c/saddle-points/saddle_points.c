#include "saddle_points.h"
#include <stdlib.h>
#include <stdbool.h>

saddle_points_t* saddle_points(int a, int b, uint8_t matrix[a][b]) 
{   
    saddle_points_t *result = malloc(sizeof(saddle_points_t));
    if (!result) return NULL;
    if (a == 0 || b == 0) {
        result->points = NULL;
        result->count = 0;
        return result;
    }
    result->count = 0;
    result->points = malloc(a * b * (sizeof(saddle_point_t)));
    if (!result->points) {
        free(result);
        return NULL;
    }

    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            bool is_col_min = true;
            bool is_row_max = true;
            for (int k = 0; k < b; ++k) {
                if (matrix[i][k] > matrix[i][j]) {
                    is_row_max = false;
                    break;
                }
            }
            for (int l = 0; l < a; ++l) {
                if (matrix[l][j] < matrix[i][j]) {
                    is_col_min = false;
                    break;
                }
            }
            if (is_col_min && is_row_max) {
                result->points[result->count].row = i + 1;
                result->points[result->count].column = j + 1;
                result->count++;
            }
        }
    }
    return result;
}

void free_saddle_points(saddle_points_t *matrix)
{
    if (matrix != NULL) {
        free(matrix->points);
        free(matrix);
    }
}
