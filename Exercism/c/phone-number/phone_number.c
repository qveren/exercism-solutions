#include "phone_number.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char *phone_number_clean(const char *input)
{
    if (!input) return NULL;
    char *new_arr = malloc(12);
    if (!new_arr) return NULL;
    
    int count = 0;
    for (int i = 0; input[i] != '\0'; ++i) {
        if (isdigit(input[i])) {
            new_arr[count++] = input[i];
        }
        else if (input[i] == ' ' || input[i] == '+' || input[i] == '(' || input[i] == ')' || input[i] == '.' || input[i] == '-') {
        }
        else {
            strcpy(new_arr, "0000000000");
            return new_arr;
        }
    }
    if (count > 11 || count < 10) {
        strcpy(new_arr, "0000000000");
        return new_arr;
    }
    if (count == 11 && new_arr[0] != '1') {
        strcpy(new_arr, "0000000000");
        return new_arr;
    }
    if (count == 11 && new_arr[0] == '1') {
        for (int i = 0; i < count - 1; ++i) {
            new_arr[i] = new_arr[i + 1];
        }
        count--;
        new_arr[count] = '\0';
    }
    if (count == 10) {
        new_arr[count] = '\0';
        if (((new_arr[0] >= '2' && new_arr[0] <= '9') && ((new_arr[3] >= '2' && new_arr[3] <= '9')))) {
            return new_arr;
        }
        else {
        strcpy(new_arr, "0000000000");
        return new_arr;
    }
    }
    return new_arr;
}
