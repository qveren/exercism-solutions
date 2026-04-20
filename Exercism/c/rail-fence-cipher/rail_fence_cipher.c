#include "rail_fence_cipher.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char *encode(char *text, size_t rails) {
    if (!text) return NULL;
    int len = strlen(text);
    if (len < 1) return NULL;
    char *result = malloc(len * sizeof(char) + 1);
    if (!result) return NULL;
    if (rails <= 1) return text;
    int step = 2 * (rails - 1);
    int count = 0;
    for (size_t r = 0; r < rails; r++) {
        int i = r;
        int next_step = 2 * (rails - 1 - r);
            while (i < len) {
                result[count++] = text[i];
                if (next_step == 0 || next_step == step) {
                    i += step;
                } else {
                    i += next_step;
                    next_step = step - next_step;
                }
            }
    }
    result[count] = '\0';
    return result;
}

char *decode(char *ciphertext, size_t rails) {
    int len = strlen(ciphertext);
    char *result = malloc(len * sizeof(char) + 1);
    int *map = malloc(len * sizeof(int));
    if (rails <= 1) return ciphertext;
    int step = 2 * (rails - 1);
    int count = 0;
    for (size_t r = 0; r < rails; r++) {
        int i = r;
        int next_step = 2 * (rails - 1 - r);
            while (i < len) {
                map[i] = count++;
                if (next_step == 0 || next_step == step) {
                    i += step;
                } else {
                    i += next_step;
                    next_step = step - next_step;
                }
            }
    }
    for (int i = 0; i < len; i++) {
        result[i] = ciphertext[map[i]];
    }
    result[len] = '\0';
    free(map);
    return result;
}