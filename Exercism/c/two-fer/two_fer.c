#include "two_fer.h"
#include <stdio.h>

void two_fer(char *buffer, const char *name)
{
    const char *who = (name == NULL || name[0] == '\0') ? "you" : name;
    sprintf(buffer, "One for %s, one for me.", who);
}
