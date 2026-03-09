#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H

char *count(const char *dna_strand);

typedef struct {
        int a;
        int c;
        int g;
        int t;
} count_letters;

#endif
