#include "binary.h"

int convert(const char *input) {
    int result = 0;
    while (*input != '\0') {
        if (*input != '0' && *input != '1') return -1;
        result = result * 2 + (*input - '0');
        input++;
    }
    return result;
}
