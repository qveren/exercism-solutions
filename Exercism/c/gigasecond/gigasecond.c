#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size) {
    if (size == 0) return;
    time_t result = input + 1000000000LL;
    struct tm *tm = gmtime(&result);
    if (tm == NULL) return;
    strftime(output, size, "%Y-%m-%d %H:%M:%S", tm);
}
