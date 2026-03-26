#include "matching_brackets.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool is_paired(const char *input)
{
    if (!input) return false;
    int top = -1;
    int length = strlen(input);
    char *stack = malloc(strlen(input) + 1);
    for (int i = 0; i < length; ++i) {
        if (input[i] == '{' || input[i] == '(' || input[i] == '[') {
            stack[++top] = input[i];
        }
        if (input[i] == '}' || input[i] == ')' || input[i] == ']') {
            if (top == -1) {
                free(stack);
                return false;
            }
            if ((input[i] == '}' && stack[top] == '{') || (input[i] == ')' && stack[top] == '(') || (input[i] == ']' && stack[top] == '[')) {
                top--;
            } else {
                free(stack);
                return false;
            }
        }
    }
    free(stack);
    if (top == -1) {
        return true;
    }
    return false;
}
