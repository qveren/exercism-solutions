#include "run_length_encoding.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encode(const char *text) {
    if (!text || strlen(text) == 0) return calloc(1, sizeof(char));
    char *result = malloc(strlen(text) * 2 + 1);
    char cur_char = text[0];
    int counter = 1, cnt = 0, len = strlen(text);
    for (size_t i = 1; i <= (size_t)len; ++i) {
        if (cur_char == text[i]) {
            counter++;
        } else {
            if (counter > 1) {
                cnt += sprintf(&result[cnt], "%d%c", counter, cur_char);
            } else {
                result[cnt++] = cur_char;
            }
            cur_char = text[i];
            counter = 1;
        }
    }
    result[cnt] = '\0';
    return result;
}
char *decode(const char *data) {
    char *result = malloc(1000);
    int count = 0, cnt = 0;
    int len = strlen(data);
    for (int i = 0; i < len; ++i) {
        if (isdigit(data[i])) {
            count = count * 10 + (data[i] - '0');
        } else {
            if (count == 0) count = 1;
            for (int j = 0; j < count; ++j) {
                result[cnt++] = data[i];
            }
        count = 0;
        }
    }
    result[cnt] = '\0';
    return result;
}