#include "pangram.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <ctype.h>

bool is_pangram(const char *sentence)
{
    if (sentence == NULL || sentence[0] == '\0') return false;
    uint32_t mask = 0;
    for (int i = 0; sentence[i] != '\0'; i++) 
        if (isalpha(sentence[i]))
            mask |= (1 << (tolower((((unsigned char)sentence[i]))) - 'a'));

    return (mask == ((1 << 26) - 1));
}
