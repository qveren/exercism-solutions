#include "protein_translation.h"
#include <string.h>

protein_t protein(const char *const rna) 
{
    codon_map table[] = {
        {"AUG", 0},
        {"UUU", 1}, {"UUC", 1},
        {"UUA", 2}, {"UUG", 2},
        {"UCU", 3}, {"UCC", 3}, {"UCA", 3}, {"UCG", 3},
        {"UAU", 4}, {"UAC", 4},
        {"UGU", 5}, {"UGC", 5},
        {"UGG", 6},
    };
    protein_t translate;
    translate.count = 0, translate.valid = true;

    if (rna == NULL || strcmp(rna, "") == 0) return translate;
    size_t length = strlen(rna);

    
    size_t i;
    for (i = 0; length - i >= 3; i += 3) {
        char codon[4] = { rna[i], rna[i+1], rna[i+2], '\0' };
        if (strncmp(codon, "UAA", 3) == 0 || strncmp(codon, "UAG", 3) == 0 || strncmp(codon, "UGA", 3) == 0) {
            return translate;
        }
        bool found = false;

        for (size_t j = 0; j < sizeof(table)/sizeof(table[0]); j++) {
            if (strncmp(codon, table[j].codon, 3) == 0) {
                found = true;
                if (translate.count < MAX_AMINO_ACIDS) {
                    translate.amino_acids[translate.count++] = table[j].protein;
                }
                found = true;
                break;
            }
        }
        if (!found) {
            translate.valid = false;
            return translate;
        }
    }
    if (rna[i] != '\0') {
        translate.valid = false;
    }
    return translate;
}
