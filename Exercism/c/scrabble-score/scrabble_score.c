#include "scrabble_score.h"
#include <string.h>
#include <stddef.h>
#include <ctype.h>

unsigned int score(const char *word)
{
    if (!word || word[0] == '\0') return 0;
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int score = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
        if (isalpha(word[i])) {
            char c = toupper(word[i]);
            int indx = c - 'A';
            score += points[indx]; 
        }
    }
    return score;
}
