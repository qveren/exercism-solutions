#include "word_count.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int count_words(const char *sentence, word_count_word_t *words) {
    memset(words, 0, sizeof(word_count_word_t) * MAX_WORDS);
    int len = strlen(sentence);
    if (!len) return 0;
    char *buffer = malloc(len * sizeof(char) + 1);
    if (!buffer) return 0;
    strcpy(buffer, sentence);

    char *delimiters = " ,.:;!?-&@$%^&\n\t";
    char *token = strtok(buffer, delimiters);

    int unique_count = 0;
    while (token != NULL) {
        int found = 0;
        int t_len = strlen(token);
        if (t_len >= 2 && token[0] == '\'' && token[t_len - 1] == '\'') {
            token[t_len - 1] = '\0';
            token++;
        }
        if (token[0] == '\0') {
            token = strtok(NULL, delimiters);
            continue;
        }
        for (int i = 0; token[i] != '\0'; i++) {
            token[i] = tolower(token[i]);
        }
        for (int j = 0; j < unique_count; j++) {
            if (strcmp(token, words[j].text) == 0) {
                words[j].count++;
                found = 1;
                break;
            }
        }
        if (found == 0) {
            strcpy(words[unique_count].text, token);
            words[unique_count].count = 1;
            unique_count++;
        }
        token = strtok(NULL, delimiters);
    }
    free(buffer);
    return unique_count;
}