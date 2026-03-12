#include "sublist.h"

static int is_contained(int *small, size_t small_count, int *large, size_t large_count)
{
    if (small_count == 0) return 1;
    if (small_count > large_count) return 0;
    if (large_count == small_count) {
        for (size_t i = 0; i < large_count; ++i) {
            if (large[i] == small[i]) {
            }
            else return 0;
        }
        return 1;
    }
    for (size_t i = 0; i <= large_count - small_count; ++i) {
        int match = 1;
        for (size_t j = 0; j < small_count; ++j)
            if (small[j] != large[i+j]) {
                match = 0;
                break;
            }
        if (match) return 1;
    }
    return 0;
}



comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count) 
{   
    if (list_to_compare_element_count == 0 && base_list_element_count == 0) return EQUAL;
    else if (list_to_compare_element_count == base_list_element_count) 
        return is_contained(base_list, base_list_element_count, list_to_compare, list_to_compare_element_count)
            ? EQUAL : UNEQUAL;

    if (list_to_compare_element_count == 0 && base_list_element_count != 0) return SUBLIST;
    else if (list_to_compare_element_count < base_list_element_count) 
        return is_contained(list_to_compare, list_to_compare_element_count, base_list, base_list_element_count)
            ? SUBLIST : UNEQUAL;

    if (list_to_compare_element_count != 0 && base_list_element_count == 0) return SUPERLIST;
    else if (list_to_compare_element_count > base_list_element_count) 
        return is_contained(base_list, base_list_element_count, list_to_compare, list_to_compare_element_count)
            ? SUPERLIST : UNEQUAL;

    return EQUAL;
}
