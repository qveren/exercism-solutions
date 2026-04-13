#include "secret_handshake.h"
#include <stdlib.h>
#include <string.h>

const char **commands(size_t number) {
    const char **result = calloc(5, sizeof(char*));
    int count = 0;
    
    if (number & 1) {
        result[count] = "wink";
        count++;
    }
    if (number & 2) {
        result[count] = "double blink";
        count++;
    }

    if (number & 4) {
        result[count] = "close your eyes";
        count++;
    }
    if (number & 8) {
        result[count] = "jump";
        count++;
    }

    int i = 0;
    int j = count - 1;
    if (number & 16) {
        while (j > i) {
            const char *tmp = result[i];
            result[i] = result[j];
            result[j] = tmp;
            i++;
            j--;
        }
    }
    result[count] = NULL;
    return result;
}