#include "clock.h"
#include <stdio.h>

clock_t clock_create(int hour, int minute) {
    int total_minutes = hour * 60 + minute;
    total_minutes = total_minutes % 1440;
    total_minutes = (total_minutes % 1440 + 1440) % 1440;
    int hours = total_minutes / 60;
    int minutes = total_minutes % 60;
    clock_t clock;
    snprintf(clock.text, MAX_STR_LEN, "%02d:%02d", hours, minutes);
    return clock;
}
clock_t clock_add(clock_t clock, int minute_add) {
    int total_minutes = ((clock.text[0] - '0') * 10 + (clock.text[1] - '0')) * 60 + ((clock.text[3] - '0') * 10 + (clock.text[4] - '0'));
    total_minutes += minute_add;
    total_minutes = (total_minutes % 1440 + 1440) % 1440;
    int hours = total_minutes / 60;
    int minutes = total_minutes % 60;
    snprintf(clock.text, MAX_STR_LEN, "%02d:%02d", hours, minutes);
    return clock;

}
clock_t clock_subtract(clock_t clock, int minute_subtract) {
    int total_minutes = ((clock.text[0] - '0') * 10 + (clock.text[1] - '0')) * 60 + ((clock.text[3] - '0') * 10 + (clock.text[4] - '0'));
    total_minutes -= minute_subtract;
    total_minutes = (total_minutes % 1440 + 1440) % 1440;
    int hours = total_minutes / 60;
    int minutes = total_minutes % 60;
    snprintf(clock.text, MAX_STR_LEN, "%02d:%02d", hours, minutes);
    return clock;
}
bool clock_is_equal(clock_t a, clock_t b) {
    int total_minutes_a = (a.text[0] * 10 + a.text[1]) + (a.text[3] * 10 + a.text[4]);
    int total_minutes_b = (b.text[0] * 10 + b.text[1]) + (b.text[3] * 10 + b.text[4]);
    if (total_minutes_a == total_minutes_b) return true;
    return false;
}
