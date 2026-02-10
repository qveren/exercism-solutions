#include "rna_transcription.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

char *to_rna(const char *dna)
{
    char *result = malloc(strlen(dna) + 1);

    char map[256] = {0};
    map['G'] = 'C';
    map['C'] = 'G';
    map['T'] = 'A';
    map['A'] = 'U';
    int i = 0;
    for (; dna[i] != '\0'; ++i){
        result[i] = map[(unsigned char)dna[i]];
    }
    result[i] = '\0';
    return result;
}
