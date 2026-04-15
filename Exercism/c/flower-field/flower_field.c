#include "flower_field.h"
#include <stdlib.h>
#include <string.h>

char **annotate(const char **garden, const size_t rows) {
    if (rows == 0) return NULL;
    size_t size = strlen(garden[0]);
    char **anno = malloc((rows + 1) * sizeof(char *));
    for (size_t i = 0; i < rows; ++i) {
        anno[i] = malloc(size + 1);
        anno[i][size] = '\0';
    }
    anno[rows] = NULL;

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < size; ++j) {
            if (garden[i][j] == '*') {
                anno[i][j] = '*';
            } 
            else if (garden[i][j] == ' ') {
                    size_t counter = 0;
                    for (int dr = -1; dr <= 1; ++dr) {
                        for (int dc = -1; dc <= 1; ++dc) {
                            if (dr == 0 && dc == 0) continue;
                            int r = (int)i + dr;
                            int c = (int)j + dc;
                            if (r >= 0 && r < (int)rows && c >= 0 && c < (int)size) {
                                if (garden[r][c] == '*') {
                                    counter++;
                                }
                            }
                        }
                    }
                if (counter > 0) {
                    anno[i][j] = counter + '0';
                } else {
                    anno[i][j] = ' ';
                }
            }
        }
    }
    return anno;
}
void free_annotation(char **annotation) {
    for (size_t i = 0; annotation[i] != NULL; ++i) {
        free(annotation[i]);
    }
    free(annotation);
}