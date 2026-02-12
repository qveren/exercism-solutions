#include "binary_search.h"
#include <stddef.h>

const int *binary_search(int value, const int *arr, size_t length)
{
    if (arr == NULL || length == 0) return NULL;
    int low = 0, high = length - 1;

        while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value) {
            return &arr[mid];
        }
        else if (arr[mid] > value) {
            high = mid - 1;
        }
        else if (arr[mid] < value) {
            low = mid + 1;
        }
    }
    return NULL;
}
