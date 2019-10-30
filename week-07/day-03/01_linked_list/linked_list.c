#include "linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

linked_list_t* list_init(int data_size) {
    linked_list_t* new_list = calloc(sizeof(linked_list_t), 1);
    new_list->size_of_data = data_size;
    return new_list;
}

void init_head(linked_list_t* list, void* data)
{
    list->head = malloc(sizeof(node_t));
    list->head->next = NULL;
    list->head->data_ptr = malloc(list->size_of_data);
    memcpy(list->head->data_ptr, data, list->size_of_data);
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
        init_head(list, data);
    }
}

void push_front(linked_list_t* list, void* data)
{
    if (list->head) {
        node_t* new = malloc(sizeof(node_t));
        new->next = list->head;
        new->data_ptr = malloc(list->size_of_data);
        memcpy(new->data_ptr, data, list->size_of_data);
        list->head = new;
    } else {
        init_head(list, data);
    }
}

int get_size(linked_list_t* list)
{
    node_t* last = list->head;
    int size = 0;
    while (last) {
        size++;
        last = last->next;
    }
    return size;
}


void print_list(void (*func)(), linked_list_t* list)
{
    node_t* it = list->head;
    while (it) {
        func(it->data_ptr);
        it = it->next;
        if(it) {
            printf(", ");
        }
    }
    printf("\n");
}