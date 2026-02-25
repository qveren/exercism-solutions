#include "dnd_character.h"
#include <stdlib.h>

int ability(void) {
    int score1 = (rand() % 6) + 1;
    int score2 = (rand() % 6) + 1;
    int score3 = (rand() % 6) + 1;
    int score4 = (rand() % 6) + 1;
    int sum = 0;
    if (score1 <= score2 && score1 <= score3 && score1 <= score4) {
        sum = score2 + score3 + score4;
    }
    else if (score2 <= score1 && score2 <= score3 && score2 <= score4) {
        sum = score1 + score3 + score4;
    }
    else if (score3 <= score1 && score3 <= score2 && score3 <= score4) {
        sum = score1 + score2 + score4;
    }
    else {
        sum = score1 + score2 + score3;
    }
    return sum;
}
int modifier(int score) {
    int value = score - 10;
    int result = value / 2;

    if (value < 0 && value % 2 != 0) {
        result--;
    }
    return result;
}
dnd_character_t make_dnd_character(void) {
    dnd_character_t character;
    character.strength = ability();
    character.dexterity = ability();
    character.constitution = ability();
    character.intelligence = ability();
    character.wisdom = ability();
    character.charisma = ability();
    character.hitpoints = 10 + modifier(character.constitution);
    return character;
}
