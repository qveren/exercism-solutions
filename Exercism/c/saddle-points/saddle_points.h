#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H
#include <inttypes.h>

typedef struct { 
    uint8_t row;
    uint8_t column;
} saddle_point_t;

typedef struct {
    int count;
    saddle_point_t *points;
} saddle_points_t;

saddle_points_t* saddle_points(int a, int b, uint8_t matrix[a][b]);
void free_saddle_points(saddle_points_t *matrix);

#endif
