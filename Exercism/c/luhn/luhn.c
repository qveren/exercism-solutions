#include "luhn.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool luhn(const char *num)
{

    int len = strlen(num);
    int digit_count = 0;
    int digit_index_from_right = 0;
    int sum = 0;
    for (int i = len - 1; i >= 0 ; i--) {
        if (isdigit(num[i])) {
            int digit = num[i] - '0';
            if (digit_index_from_right % 2 == 1) {
                digit *= 2;
                if (digit > 9) {
                    digit -= 9;

                }
            }
            digit_index_from_right += 1;
            sum += digit;
            digit_count++;
        }
        else if (!isspace(num[i])) return false;
    }
    if (digit_count < 2) return false;
    if (sum % 10 == 0) return true;
    return false;
}
