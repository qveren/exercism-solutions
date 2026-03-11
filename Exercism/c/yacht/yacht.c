#include "yacht.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int compare(const void *a, const void *b) 
{
    return (*(uint8_t *) a - * (uint8_t *) b);
}


int score(dice_t dice, category_t category)
{
    uint8_t sorted[5];
    for (uint8_t i = 0; i < 5; i++) {
        sorted[i] = dice.faces[i];
    }
    qsort(sorted, 5, sizeof(uint8_t), compare);

    int count = 0;

    if (category >= ONES && category <= SIXES) {
        int target = category + 1;
        for (int i = 0; i < 5; i++) {
            if (sorted[i] == target) count += target;
        }
        return count;
    }

    switch (category) {
        case YACHT:
            if (sorted[0] == sorted[4]) {
                return 50;
            }
            else return 0;
        case CHOICE:
            for (int i = 0; i < 5; ++i) {
                count += sorted[i]; 
            }
            return count;
        case LITTLE_STRAIGHT:
            if (sorted[0] == 1 && sorted[1] == 2 && sorted[2] == 3 && sorted[3] == 4 && sorted[4] == 5) {
                return 30;
            } 
            else return 0;
        case BIG_STRAIGHT:
            if (sorted[0] == 2 && sorted[1] == 3 && sorted[2] == 4 && sorted[3] == 5 && sorted[4] == 6) {
                return 30;
            }
            else return 0;
        case FOUR_OF_A_KIND:
            if (sorted[0] == sorted[3]) {
                count = sorted[0] * 4;
                return count;
            }
            else if (sorted[1] == sorted[4]) {
                count = sorted[1] * 4;
                return count;
            }
            else return 0;

        case FULL_HOUSE:
            if (sorted[0] == sorted[1] && sorted[2] == sorted[4] && sorted[0] != sorted[4]) {
                for (int i = 0; i < 5; ++i) {
                    count += sorted[i];
                }
                return count;        
            }
            else if (sorted[0] == sorted[2] && sorted[3] == sorted[4] && sorted[0] != sorted[4]) {
                for (int i = 0; i < 5; ++i) {
                    count += sorted[i];
                }
                return count;
            }
            else return 0;
        default:
            break;
    }
    return count;
}
