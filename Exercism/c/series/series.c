#include "series.h"
#include <string.h>
#include <stdlib.h>

slices_t slices(char *input_text, unsigned int substring_length) {
    slices_t jopa;
    size_t len_txt = strlen(input_text);
    if (len_txt < substring_length || substring_length == 0) {
        jopa.substring = 0;
        jopa.substring_count = 0;
        return jopa;
    }
    char **substrings = malloc((strlen(input_text)-substring_length+1) * sizeof(char *));
    
    size_t current = 0;
    for (; current <= (len_txt - substring_length); current++) { 
        substrings[current] = malloc(substring_length +1);
        for (unsigned int i = 0; i < substring_length; ++i) {
            substrings[current][i] = input_text[current + i];
        }
        substrings[current][substring_length] = '\0';
    }
    jopa.substring = substrings;
    jopa.substring_count = current;
    return jopa;
}
