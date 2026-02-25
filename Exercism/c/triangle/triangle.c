#include "triangle.h"
const double EPSILON = 1e-9;

bool is_equilateral(triangle_t sides) {
    if (sides.a <= 0 || sides.b <= 0 || sides.c <= 0) return false;
    if (sides.a + sides.b < sides.c || sides.a + sides.c < sides.b || sides.b + sides.c < sides.a) return false;
    if (sides.a == sides.b && sides.b == sides.c) return true;
    return false;
}
bool is_isosceles(triangle_t sides) {
    if (sides.a <= 0 || sides.b <= 0 || sides.c <= 0) return false;
    if (sides.a + sides.b < sides.c || sides.a + sides.c < sides.b || sides.b + sides.c < sides.a) return false;
    if (sides.a == sides.b || sides.b == sides.c || sides.a == sides.c) return true;
    return false;
}
bool is_scalene(triangle_t sides) {
    if (sides.a <= 0 || sides.b <= 0 || sides.c <= 0) return false;
    if (sides.a + sides.b < sides.c || sides.a + sides.c < sides.b || sides.b + sides.c < sides.a) return false;
    if (sides.a != sides.b && sides.b != sides.c && sides.a != sides.c) return true;
    return false;
}
