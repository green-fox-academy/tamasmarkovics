#include "linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

linked_list_t* list_init(enum data_type type_of_data) {
    linked_list_t* new_list = calloc(sizeof(linked_list_t), 1);
    new_list->size_of_data = get_data_size(type_of_data);
    new_list->type_of_data = type_of_data;
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

void erase_at(linked_list_t* list, int at)
{
    node_t* from = list->head;
    if (at) {
        for (int i = 1; i < at; i++) {
            from = from->next;
        }
        if (from->next) {
            node_t *temp = from->next->next;
            free(from->next->data_ptr);
            free(from->next);
            from->next = temp;
        } else {
            free(from->next->data_ptr);
            free(from->next);
            from->next = NULL;
        }
    } else {
        from = from->next;
        free(list->head->data_ptr);
        free(list->head);
        list->head = from;
    }

}

void delete(linked_list_t* list)
{
    node_t* temp = list->head->next;
    free(list->head->data_ptr);
    free(list->head);
    list->head = temp;
}


void empty(linked_list_t* list)
{
    while (list->head) {
        delete(list);
    }
}


int search_list(linked_list_t* list, void* what)
{
    node_t* at = list->head;
    int index = 0;
    while (at) {
        int found = 1;
        for (int j = 0; j < list->size_of_data; ++j) {
            if (((char*)at->data_ptr)[j]  != ((char*)what)[j]) {
                found = 0;
            }
        }
        if (found) return index;
        index++;
        at = at->next;
    }
    return -1;
}

void delete_all_value(linked_list_t* list, void* what)
{
    int i = search_list(list, what);
    while (i != -1) {
        erase_at(list, i);
        i = search_list(list, what);
    }
}

//NOT WORKING ATM
void bubble_sort(linked_list_t* to_sort)
{
    node_t* fake_start = malloc(sizeof(node_t));
    node_t* fake_start2 = malloc(sizeof(node_t));
    fake_start->next = to_sort->head;

    for (; fake_start->next; fake_start = fake_start->next) {
        for (; fake_start2->next->next; fake_start2 = fake_start2->next) {
            if (*(double *)fake_start2->next->data_ptr > *(double *)(fake_start2->next->next->data_ptr)) {
                node_t* bigger = fake_start->next;             //address of the first
                node_t* smaller = fake_start->next->next;       //address of the second
                node_t* forthcoming = fake_start->next->next->next; //address of the next
                fake_start->next = smaller;
                smaller->next = bigger;
                bigger->next = forthcoming;
            }
        }
    }
    free(fake_start);
    free(fake_start2);
}

int get_data_size(enum data_type data) {
    switch (data) {
        case INT :
            return sizeof(int);
        case DOUBLE :
            return sizeof(double);
        case FLOAT :
            return sizeof(float);
        case CHAR :
            return sizeof(char);
        default:
            return -1;
    }
}