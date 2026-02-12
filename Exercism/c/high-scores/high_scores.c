#include "high_scores.h"
#include <stddef.h>

int32_t latest(const int32_t *scores, size_t scores_len)
{
    if (scores == NULL || scores_len == 0) return 0;
    return scores[scores_len-1];
}
int32_t personal_best(const int32_t *scores, size_t scores_len)
{
    if (scores == NULL || scores_len == 0) return 0;
    int best = scores[0];
    for (int i = 0; i < (int)scores_len; i++) {
        if (best < scores[i]) {
            best = scores[i];
        }
    }
    return best;
}
size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output)
{
    if (scores == NULL || scores_len == 0) return 0;
    int best = 0, second = 0, three = 0;
    for (int i = 0; i < (int)scores_len; i++) {
        if (best < scores[i]) {
            three = second;
            second = best;
            best = scores[i];
        }
        else if (second < scores[i]) {
            three = second;
            second = scores[i];
        }
        else if (three < scores[i]) {
            three = scores[i];
        }
    }
    output[0] = best;
    if (scores_len > 1) output[1] = second;
    if (scores_len > 2) output[2] = three;
    return (scores_len < 3) ? scores_len : 3;
}
