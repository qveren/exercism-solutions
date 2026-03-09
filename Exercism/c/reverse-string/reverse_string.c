#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>

char *reverse(const char *value)
{
    if (value == NULL) return NULL;
    size_t length = strlen(value);
    char *new_string = malloc(length + 1);
    if (new_string == NULL) return NULL;
    for (size_t i = 0; i < length; ++i) {
        new_string[i] = value[length - i - 1];
    }
    new_string[length] = '\0';
    return new_string;
}
