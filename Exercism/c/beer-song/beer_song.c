#include "beer_song.h"
#include <stdio.h>
#include <stdbool.h>

void recite(uint8_t start_bottles, uint8_t take_down, char **song)
{
    uint8_t bottles;

    for (uint8_t i = 0; i < take_down; i++) {
        bottles = start_bottles - i;
        if (bottles > 2) {
            sprintf(song[i * 3],"%d bottles of beer on the wall, %d bottles of beer.", bottles, bottles);
            sprintf(song[i * 3 + 1], "Take one down and pass it around, %d bottles of beer on the wall.", bottles-1);

        }
        else if (bottles == 2) {
            sprintf(song[i * 3],"%d bottles of beer on the wall, %d bottles of beer.", bottles, bottles);

            sprintf(song[i * 3 + 1], "Take one down and pass it around, %d bottle of beer on the wall.", bottles-1);

        }
        else if (bottles == 1) {
            sprintf(song[i * 3],"%d bottle of beer on the wall, %d bottle of beer.", bottles, bottles);

            sprintf(song[i * 3 + 1], "Take it down and pass it around, no more bottles of beer on the wall.");

        }
        else {
            sprintf(song[i * 3], "No more bottles of beer on the wall, no more bottles of beer.");
            sprintf(song[i * 3 + 1], "Go to the store and buy some more, 99 bottles of beer on the wall.");

        }
    if (i < take_down - 1) {
        song[i * 3 + 2][0] = '\0';
    }
    }
    
}
