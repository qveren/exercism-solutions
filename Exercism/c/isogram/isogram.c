#include "isogram.h"
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>

bool is_isogram(const char *phrase)
{
    char alphabet[26] = {0};
    if (phrase == NULL) return false;
    for (int i = 0; phrase[i] != '\0'; ++i) {
        char current = phrase[i];
        if (isalpha(current)) {
            char low_case = tolower(current);
            short letter = low_case - 'a';
            if (alphabet[letter] == 0) {
                alphabet[letter] = 1;
            }
            else {
                return false;
            } 
        }
    }
    return true;
}
