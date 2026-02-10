#include "rna_transcription.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

char *to_rna(const char *dna)
{
    char *result = malloc(strlen(dna) + 1);
    int j = 0;

    for (int i = 0; dna[i] != '\0'; ++i) {
        if (dna[i] == 'G') {
            result[j] = 'C';
            j++;
        }
        if (dna[i] == 'C') {
            result[j] = 'G';
            j++;
        }
        if (dna[i] == 'T') {
            result[j] = 'A';
            j++;
        }
        if (dna[i] == 'A') {
            result[j] = 'U';
            j++;
        }
    }
    result[j] = '\0';
    return result;
}
