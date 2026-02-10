#include "hamming.h"
#include <stddef.h>

int compute(const char *lhs, const char *rhs)
{   
    if (lhs == NULL || rhs == NULL) return -1;
    
    int count = 0;
    for (int i = 0; lhs[i] != '\0' || rhs[i] != '\0'; ++i) {
        if ((lhs[i] == '\0' && rhs[i] != '\0') || (lhs[i] != '\0' && rhs[i] == '\0')) return -1;
        else if (lhs[i] != rhs[i]) count++;
    }
    return count;
}
