#include "sublist.h"

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count) 
{
    
    if (list_to_compare_element_count == 0 && base_list_element_count == 0) return EQUAL;

    else if (list_to_compare_element_count == base_list_element_count) {
        for (size_t i = 0; i < list_to_compare_element_count; ++i) {
            if (list_to_compare[i] == base_list[i]) {
            }
            else return UNEQUAL;
        }
        return EQUAL;
    }

    if (list_to_compare_element_count == 0 && base_list_element_count != 0) return SUBLIST;
    else if (list_to_compare_element_count < base_list_element_count) {
        for (size_t i = 0; i <= base_list_element_count - list_to_compare_element_count; ++i) {
            int match = 1;
            for (size_t j = 0; j < list_to_compare_element_count; ++j)
                if (list_to_compare[j] != base_list[i + j]) {
                    match = 0;
                    break;
                }
            if (match) return SUBLIST;
        }
        return UNEQUAL;
    }

    if (list_to_compare_element_count != 0 && base_list_element_count == 0) return SUPERLIST;
    else if (list_to_compare_element_count > base_list_element_count) {
        for (size_t i = 0; i <= list_to_compare_element_count - base_list_element_count; ++i) {
            int match = 1;
            for (size_t j = 0; j < base_list_element_count; ++j)
                if (base_list[j] != list_to_compare[i+j]) {
                    match = 0;
                    break;
                }
            if (match) return SUPERLIST;
        }
        return UNEQUAL;
    }
    return EQUAL;
}
