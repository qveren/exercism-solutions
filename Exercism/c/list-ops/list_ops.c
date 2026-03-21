#include "list_ops.h"
#include <stdlib.h>
#include <string.h>

// constructs a new list
list_t *new_list(size_t length, list_element_t elements[])
{
    if (elements == 0 || length == 0) return NULL;
    list_t *list = malloc(sizeof(list_t) + length * sizeof(list_element_t));
    if (!list) return NULL;

    list->length = length;
    memcpy(list->elements, elements, length * sizeof(list_element_t));
    return list;
}

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2)
{
    if (list1 == NULL || list2 == NULL) return NULL;
    size_t full_length = list1->length + list2->length;
    size_t full_size = sizeof(list_t) + full_length * sizeof(list_element_t);
    list_t *new_list = malloc(sizeof(list_t) + full_length * sizeof(list_element_t));
    if (!new_list) return NULL;
    new_list->length = full_length;
    memcpy(new_list->elements, list1->elements, list1->length * sizeof(list_element_t));
    memcpy(new_list->elements + list1->length, list2->elements, list2->length * sizeof(list_element_t));    
    return new_list;
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t))
{
    size_t count = 0;
    for (size_t i = 0; i < list->length; ++i) {
        if (filter(list->elements[i])) {
            count++;
        }
    }
    list_t *list_filter = malloc(sizeof(list_t) + count * sizeof(list_element_t));
    if (!list_filter) return 0;

    size_t idx = 0;
    for (size_t i = 0; i < list->length; ++i) {    
        if (filter(list->elements[i])) {
            list_filter->elements[idx++] = list->elements[i];
        }
    }
    list_filter->length = count;
    
    return list_filter;
}

// returns the length of the list
size_t length_list(list_t *list) 
{
    if (!list) return 0;
    return list->length;
}

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t))
{
    if (!list) return NULL;
    list_t *new_list = malloc(sizeof(list_t) + list->length * sizeof(list_element_t));
    if (!new_list) return NULL;
    for (int i = 0; i < list->length; ++i) {
        new_list->elements[i] = map(list->elements[i]);
    }
    new_list->length = list->length;

    return new_list;
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t));

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t));

// reverse the elements of the list
list_t *reverse_list(list_t *list)
{
    if (!list) return NULL;
    list_t *new_list = malloc(sizeof(list_t) + list->length * sizeof(list_element_t));
    if (!new_list) return NULL;
    for (int i = 0; i < list->length; ++i) {
        new_list->elements[list->length - 1 - i] = list->elements[i];
    }
    new_list->length = list->length;
    return new_list;
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list) 
{
    free(list);
}
