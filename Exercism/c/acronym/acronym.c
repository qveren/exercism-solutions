#include "acronym.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

char *abbreviate(const char *phrase)
{
    bool flag = true;
    int j = 0;

    if (phrase == NULL) return NULL;
    if (strlen(phrase) == 0) return NULL;
    char *result = malloc(strlen(phrase) + 1);
    if (result == NULL) return NULL;


    for (int i = 0; phrase[i] != '\0'; i++) {
        if (isalpha(phrase[i]) && flag == true) {
            result[j] = toupper(phrase[i]);
            flag = false;
            j++;
        } 
        else if ((isspace(phrase[i]) || phrase[i] == '-' || phrase[i] == '_') && flag == false) {
            flag = true;
        }
    }
    result[j] = '\0';
    return result;
}
