#include "nucleotide_count.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *count(const char *dna_strand)
{
    count_letters counter;
    counter.a = 0, counter.c = 0, counter.g = 0, counter.t = 0;
    
    char *error = malloc(1);

    if (NULL == dna_strand) return NULL;
    for (size_t i = 0; dna_strand[i] != '\0'; ++i) {
        if (dna_strand[i] == 'A') {
            counter.a++;
        }
        else if (dna_strand[i] == 'C') {
            counter.c++;
        }
        else if (dna_strand[i] == 'G') {
            counter.g++;
        }
        else if (dna_strand[i] == 'T') {
            counter.t++;
        }
        else return error;
    }
    size_t needed = snprintf(NULL, 0, "A:%d C:%d G:%d T:%d", counter.a, counter.c, counter.g, counter.t) + 1;
    char *string = malloc(needed);
    if (!string) return NULL;
    snprintf(string, needed, "A:%d C:%d G:%d T:%d", counter.a, counter.c, counter.g, counter.t);
    return string;
}
