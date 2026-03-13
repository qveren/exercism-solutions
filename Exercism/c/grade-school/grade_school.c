#include "grade_school.h"


int init_roster(roster_t *roster) {
    roster->count = 0;
    return 0;
}
int add_student(roster_t *roster, const char *name, int grade)
{
    if (roster->count >= MAX_STUDENTS) return 1;
    for (size_t k = 0; k < roster->count; k++) {
        if (strcmp(roster->students[k].name, name) == 0) return 0;
    }
    size_t i = 0;
    while (i < roster->count) {
        if (roster->students[i].grade > grade) {
            break;
        }
        if (roster->students[i].grade == grade && strcmp(roster->students[i].name, name) > 0) {
            break;
        }
        i++;
    }
    size_t j;
    for (j = roster->count; j > i; --j) {
        roster->students[j] = roster->students[j-1];
    }

    strcpy(roster->students[i].name, name);
    roster->students[i].grade = grade;
    roster->count++;
    return 1;
}
roster_t get_grade(roster_t *roster, uint8_t grade)
{
    roster_t result;
    result.count = 0;
    size_t i = 0;
    while (i < roster->count) {
        if (roster->students[i].grade == grade) {
            result.students[result.count] = roster->students[i];
            result.count++;
        }
        i++;
    }

    return result;
}
