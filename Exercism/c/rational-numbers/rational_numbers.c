#include "rational_numbers.h"
#include <stdlib.h>
#include <math.h>

rational_t add(rational_t r1, rational_t r2) {
    int denom = r1.denominator * r2.denominator;
    int num = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    rational_t sum;
    sum.numerator = num;
    sum.denominator = denom;
    return reduce(sum);
}
rational_t subtract(rational_t r1, rational_t r2) {
    rational_t r2_copy;
    r2_copy.numerator = -r2.numerator;
    r2_copy.denominator = r2.denominator;
    return add(r1, r2_copy);
}
rational_t multiply(rational_t r1, rational_t r2) {
    int denom = r1.denominator * r2.denominator;
    int num = r1.numerator * r2.numerator;
    rational_t mul;
    mul.numerator = num;
    mul.denominator = denom;
    return reduce(mul);
}
rational_t divide(rational_t r1, rational_t r2) {
    if (r2.numerator == 0) return r2;
    rational_t r2_fliped; 
    r2_fliped.numerator = r2.denominator;
    r2_fliped.denominator = r2.numerator;
    return multiply(r1, r2_fliped);
}
rational_t absolute(rational_t r) 
{
    r.numerator = abs(r.numerator);
    r.denominator = abs(r.denominator);
    return reduce(r);
}
rational_t exp_rational(rational_t r, int n) {
    if (n > 0) {
        r.numerator = pow(r.numerator, n);
        r.denominator = pow(r.denominator, n);
        return reduce(r);
    }
    if (n < 0) {
        int tmp = r.numerator;
        r.numerator = r.denominator;
        r.denominator = tmp;
        r.numerator = pow(r.numerator, abs(n));
        r.denominator = pow(r.denominator, abs(n));
        return reduce(r);
    }
    else {
        r.denominator = 1;
        r.numerator = 1;
        return r;
    }

}
float exp_real(uint16_t x, rational_t r) 
{
    double r_num = r.numerator;
    double r_denom = r.denominator;
    double div = r_num / r_denom;
    double exp = pow(x, div);
    return exp;
}
rational_t reduce(rational_t r)
{
    if (r.denominator == 0) return r;
    if (r.numerator == 0) {
        r.numerator = 0;
        r.denominator = 1;
        return r;
    }
    int a = abs(r.numerator);
    int b = abs(r.denominator);

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    if (r.denominator < 0) {
        r.numerator = -r.numerator;
        r.denominator = -r.denominator;
    }
    r.numerator /= a;
    r.denominator /= a;
    return r; 
}
