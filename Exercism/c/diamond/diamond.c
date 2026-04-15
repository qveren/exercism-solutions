#include "diamond.h"
#include <stdlib.h>
#include <string.h>

char **make_diamond(const char letter) {
    size_t n = letter - 'A';
    size_t size = (n * 2) + 1;
    char **diamond = malloc(size * sizeof(char *));
    for (size_t i = 0; i < size; ++i) {
        diamond[i] = malloc(size + 1);
    }
    for (size_t i = 0; i < size; ++i) {
        size_t step = (i <= n) ? i : (size - 1 - i);
        char required_letter = letter - (n - step);
        memset(diamond[i], ' ', size);
        diamond[i][n-step] = required_letter;
        diamond[i][n+step] = required_letter;
        diamond[i][size] = '\0';
    }
    return diamond;
}
void free_diamond(char **diamond) {
    for (size_t i = 0; i != '\0'; ++i) {
        free(diamond[i]);
    }
    free(diamond);
}