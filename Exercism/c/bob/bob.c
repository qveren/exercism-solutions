#include "bob.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *hey_bob(char *greeting) {
    int has_alpha = 0;
    int is_all_upper = 1;
    int has_non_space = 0;
    int is_question = 0;
    size_t len_word = strlen(greeting);

    for (size_t i = 0; i < len_word; ++i) {
        if (!isspace(greeting[i])) {
            has_non_space = 1; 
            if (isalpha(greeting[i])) {
                has_alpha = 1;
                if (!isupper(greeting[i])) {
                    is_all_upper = 0;
                }
            }
        }
    }
    
    int i = len_word - 1;
    while (i >= 0 && isspace(greeting[i])) {
        i--;
    }

    if (i >= 0 && greeting[i] == '?') {
        is_question = 1;
    }

    if (has_non_space == 0) {
        return "Fine. Be that way!";
    }
    else if (has_alpha == 1 && is_question == 1 && is_all_upper == 1) {
        return "Calm down, I know what I'm doing!";
    }
    else if (has_alpha == 1 && is_all_upper == 1) {
        return "Whoa, chill out!";
    }
    else if (is_question == 1) {
        return "Sure.";
    } else {
        return "Whatever.";
    }
    
}
