#include "roman_numerals.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned int value;
    char *symbol;
} roman_map;

roman_map roman_lookup[] = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
    {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
    {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
    {1, "I"}
};

char *to_roman_numeral(unsigned int number) 
{
    char *roman_num = calloc(15, sizeof(char));
    if (!roman_num) return NULL;

    for (int i = 0; i < 13; ++i) {
        while (number >= roman_lookup[i].value) {
            strcat(roman_num, roman_lookup[i].symbol);
            number -= roman_lookup[i].value;
        }
    }
    return roman_num;
}
