#include "rotational_cipher.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char *rotate(const char *text, int shift_key) {
    char *new_string = malloc(strlen(text) + 1);
    for (unsigned long i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (text[i] >= 'A' && text[i] <= 'Z') {
                new_string[i] = 'A' + (text[i] - 'A' + shift_key) % 26;
            }
            else if (text[i] >= 'a' && text[i] <= 'z') {
                new_string[i] = 'a' + (text[i] - 'a' + shift_key) % 26;
            }
        }
        else {
            new_string[i] = text[i];
        }
    }
    new_string[strlen(text)] = '\0';
    return new_string;
}
