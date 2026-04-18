#include "atbash_cipher.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


char *atbash_encode(const char *input) {
    if (!input) return NULL;
    int len = strlen(input), count = 0, added_chars = 0;
    char *result = malloc(len + (len / 5) + 1);
    for (int i = 0; input[i] != '\0'; ++i) {
        if (isalnum(input[i])) {
            if (added_chars % 5 == 0 && added_chars > 0) {
                result[count++] = ' ';
            }
            if (isalpha(input[i])) {
                result[count++] = 'a' + (25 - (tolower((unsigned char)input[i]) - 'a'));
            } else {
                result[count++] = input[i];
            }
            added_chars++;
        }
    }
    result[count] = '\0';
    return result;
}

char *atbash_decode(const char *input) {
    if (!input) return NULL;
    char *result = malloc(strlen(input) + 1);
    int count = 0;
    for (int i = 0; input[i] != '\0' ; ++i) {
        if (isalnum(input[i])) {
            if (isalpha(input[i])) {
                result[count++] = 'a' + (25 - (tolower((unsigned char)input[i]) - 'a'));
            } else {
                result[count++] = input[i];
            }
        }
    }
    result[count] = '\0';
    return result;
}