#include "linked_list.h"
#include <stdlib.h>

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};

struct list *list_create(void) 
{
   struct list *new_list = malloc(sizeof(struct list));
   if (new_list == NULL) return NULL;
   new_list->first = NULL;
   new_list->last = NULL;

   return new_list;
}

void list_push(struct list *list, ll_data_t item_data)
{
   struct list_node* new_node = malloc(sizeof(struct list_node));
   if (!new_node) return;
   
   new_node->data = item_data;
   new_node->next = NULL;

   if ((list->last) == NULL) {
      list->first = new_node; 
      list->last = new_node;
      new_node->prev = NULL;
   } else {
      new_node->prev = list->last;
      list->last->next = new_node;
      list->last = new_node;
   }
}

ll_data_t list_pop(struct list *list) 
{
   struct list_node *node_no_pop = list->last;
   ll_data_t data = node_no_pop->data;
   list->last = node_no_pop->prev;

   if (list->last == NULL) {
      list->first = NULL;
   } else {
      list->last->next = NULL;
   }
   free(node_no_pop);

   return data;
}
ll_data_t list_shift(struct list* list)
{
   struct list_node *shift = list->first;
   if (!shift) return 0;
   ll_data_t data = shift->data;
   list->first = shift->next;

   if (list->first == NULL) {
      list->last = NULL;
   } else {
      list->first->prev = NULL;
   }
   free(shift);

   return data;
}
void list_unshift(struct list *list, ll_data_t item_data) 
{
   struct list_node* new_node = malloc(sizeof(struct list_node));
   if (!new_node) return;
   new_node->prev = NULL;
   new_node->next = list->first;
   new_node->data = item_data;
   if (list->first == NULL) {
      list->last = new_node;
   } else {
      list->first->prev = new_node;
   }
   list->first = new_node;
}
size_t list_count(const struct list *list)
{
   struct list_node* current = list->first;
   size_t count = 0;
   while (current != NULL) {
      count++;
      current = current->next;
   }
   return count;
}

void list_delete(struct list *list, ll_data_t data) 
{
   struct list_node* current = list->first;
   while (current != NULL && current->data != data) {
      current = current->next;
   }
   if (current == NULL) return;
   if (current->prev != NULL) {
      current->prev->next = current->next;
   } else {
      list->first = current->next;
   }
   if (current->next != NULL) {
      current->next->prev = current->prev;
   } else {
      list->last = current->prev;
   }
   free(current);
   return;
}

void list_destroy(struct list *list) 
{
   while ((list->first) != NULL) {
      list_pop(list);
   }
   free(list);
   return;
}
