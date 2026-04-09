#include "anagram.h"
#include <ctype.h>
#include <strings.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void find_anagrams(const char *subject, struct candidates *candidates) {
    for (size_t i = 0; i < candidates->count; i++) {
    const char *word = candidates->candidate[i].word;

    bool is_anagram = true;

    int count[256] = {0};

    size_t len_subject = strlen(subject);
    size_t len_word = strlen(word);

    if (len_subject != len_word) {
        is_anagram = false;
        candidates->candidate[i].is_anagram = NOT_ANAGRAM;
        continue;
    }

    // заполнение count из subject
    for (size_t j = 0; j < len_subject; j++) {
        char c = tolower(subject[j]);
        count[(unsigned char)c]++;
    }

    // вычитание word
    for (size_t j = 0; j < len_word; j++) {
        char c = tolower(word[j]);
        count[(unsigned char)c]--;
    }

    // проверка
    for (int k = 0; k < 256; k++) {
        if (count[k] != 0) {
            is_anagram = false;
            break;
        }
    }

    // одинаковые слова — не анаграмма
    if (strcasecmp(subject, word) == 0) {
        is_anagram = false;
    }

    if (is_anagram)
        candidates->candidate[i].is_anagram= IS_ANAGRAM;
    else
        candidates->candidate[i].is_anagram = NOT_ANAGRAM;
    }
}