#include "perfect_numbers.h"

kind classify_number(int number)
{
    if (number < 1) return -1;
    int sum = 0;
    for (int i = 1; i <= number / 2; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }
    if (sum == number) return 1;
    else if (sum > number) return 2;
    else return 3;
}
