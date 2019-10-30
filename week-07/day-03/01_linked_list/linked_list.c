#include "linked_list.h"
#include <stdlib.h>
#include <string.h>

linked_list_t* list_init(int data_size) {
    linked_list_t* new_list = calloc(sizeof(linked_list_t), 1);
    new_list->size_of_data = data_size;
    return new_list;
}


void push_back(linked_list_t* list, void* data)
{
    if (list->head) {
        node_t *last = list->head;
        while (last->next) last = last->next;
        last->next = malloc(sizeof(node_t));
        last->next->next = NULL;
        last->next->data_ptr = malloc(list->size_of_data);
        memcpy(last->next->data_ptr, data, list->size_of_data);
    } else {
        list->head = malloc(sizeof(node_t));
        list->head->next = NULL;
        list->head->data_ptr = malloc(list->size_of_data);
        memcpy(list->head->data_ptr, data, list->size_of_data);
    }
}