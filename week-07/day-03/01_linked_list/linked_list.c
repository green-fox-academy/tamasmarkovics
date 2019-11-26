#include "linked_list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

linked_list_t* list_init(enum data_type type_of_data)
{
    linked_list_t* new_list = calloc(sizeof(linked_list_t), 1);
    new_list->size_of_data = get_data_size(type_of_data);
    new_list->type_of_data = type_of_data;
    return new_list;
}

void init_head(linked_list_t* to_init, void* head_data)
{
    to_init->head = malloc(sizeof(node_t));
    to_init->head->next = NULL;
    to_init->head->data_ptr = malloc(to_init->size_of_data);
    memcpy(to_init->head->data_ptr, head_data, to_init->size_of_data);
}

void push_back(linked_list_t* push_in, void* data_to_push)
{
    if (push_in->head) {
        node_t *last_node = push_in->head;
        while (last_node->next) last_node = last_node->next;

        last_node->next = malloc(sizeof(node_t));
        last_node->next->next = NULL;

        last_node->next->data_ptr = malloc(push_in->size_of_data);
        memcpy(last_node->next->data_ptr, data_to_push, push_in->size_of_data);

    } else init_head(push_in, data_to_push);
}

void push_front(linked_list_t* push_front_in, void* data_to_push)
{
    if (push_front_in->head) {
        node_t* new_node = malloc(sizeof(node_t));

        new_node->next = push_front_in->head;
            new_node->data_ptr = malloc(push_front_in->size_of_data);
        memcpy(new_node->data_ptr, data_to_push, push_front_in->size_of_data);

        push_front_in->head = new_node;

    } else init_head(push_front_in, data_to_push);
}

int get_size(linked_list_t* get_size_of)
{
    int size_of_list = 0;

    node_t* last_node = get_size_of->head;
    while (last_node) {
        size_of_list++;
        last_node = last_node->next;
    }

    return size_of_list;
}


void erase_at(linked_list_t* erase_in, int at_index)
{
    if (!(at_index >= 0 && at_index < get_size(erase_in))) return;

    node_t* erase_from = erase_in->head;

    if (at_index != 0) {
        for (int i = 1; i < at_index; i++) {
            erase_from = erase_from->next;
        }
        if (erase_from->next) {
            node_t *temp = erase_from->next->next;
            free(erase_from->next->data_ptr);
            free(erase_from->next);
            erase_from->next = temp;
        } else {
            free(erase_from->next->data_ptr);
            free(erase_from->next);
            erase_from->next = NULL;
        }
    } else {
        erase_from = erase_from->next;
        free(erase_in->head->data_ptr);
        free(erase_in->head);
        erase_in->head = erase_from;
    }

}

void delete_head(linked_list_t* to_delete)
{
    node_t *temp = to_delete->head->next;

    free(to_delete->head->data_ptr);
    free(to_delete->head);

    to_delete->head = temp;
}

void empty(linked_list_t* to_empty)
{
    while (to_empty->head) {
        delete_head(to_empty);
    }
}

int search_list(linked_list_t* search_in, void* for_what)
{
    node_t* at = search_in->head;
    int index_of_target = 0;

    while (at) {
        int found = 1;
        for (int j = 0; j < search_in->size_of_data; ++j) {
            if (((char*)at->data_ptr)[j]  != ((char*)for_what)[j]) {
                found = 0;
            }
        }
        if (found) return index_of_target;
        index_of_target++;
        at = at->next;
    }

    return -1;
}

void delete_all_by_value(linked_list_t* delete_in, void* what)
{
    int i = search_list(delete_in, what);
    while (i != -1) {
        erase_at(delete_in, i);
        i = search_list(delete_in, what);
    }
}

int get_data_size(enum data_type type_of_data) {
    switch (type_of_data) {
        case INT :
            return sizeof(int);
        case DOUBLE :
            return sizeof(double);
        case FLOAT :
            return sizeof(float);
        case CHAR :
            return sizeof(char);
        default:
            return 0;
    }
}

//****  PRINT UTILITY  ****//

void* get_printer(linked_list_t* list_to_print) {
    switch (list_to_print->type_of_data) {
        case INT :
            return print_int;
        case DOUBLE :
            return print_dbl;
        case FLOAT :
            return print_float;
        case CHAR :
            return print_char;
        default:
            return print_char;
    }
}

void print_int(void* int_to_print) {
    printf("%d", *(int*)int_to_print);
}
void print_dbl(void* double_to_print) {
    printf("%0.3lf", *(double*)double_to_print);
}
void print_float(void* float_to_print) {
    printf("%0.2f", *(float*)float_to_print);
}
void print_char(void* char_to_print) {
    printf("%c", *(char*)char_to_print);
}

void print_list(linked_list_t* to_print)
{
    node_t* current = to_print->head;
    void (*print_func)(void*);
    print_func = get_printer(to_print);

    while (current) {
        print_func(current->data_ptr);

        current = current->next;

        if(current) {
            printf(", ");
        } else printf("\n");
    }
}

//****  COMPARE  ****//
int compare_void(linked_list_t* compare_in, node_t* first)
{
    int (*compare_func)(void*);
    compare_func = get_comparer(compare_in);
    return compare_func(first);
}

void* get_comparer(linked_list_t* compare_in)
{
    switch (compare_in->type_of_data) {
        case INT :
            return compare_int;
        case DOUBLE :
            return compare_dbl;
        case FLOAT :
            return compare_float;
        case CHAR :
            return compare_char;
        default:
            return compare_char;
    }
}

int compare_int(node_t* first)
{
    return *(int*)(first->data_ptr) > *(int*)(first->next->data_ptr);
}

int compare_dbl(node_t* first)
{
    return *(double*)(first->data_ptr) > *(double*)(first->next->data_ptr);
}

int compare_float(node_t* first)
{
    return *(float*)(first->data_ptr) > *(float*)(first->next->data_ptr);
}

int compare_char(node_t* first)
{
    return *(char*)(first->data_ptr) > *(char*)(first->next->data_ptr);
}

//****  SWAP  ****//
void swap_address(linked_list_t* swap_in, node_t* first)
{
    //SWAPPING THE HEAD
    if (swap_in->head == first) {
        node_t* one = first;
        node_t* two = first->next;
        swap_in->head = two;
        one->next = two->next;
        two->next = one;
        return;
    }

    //SWAPPING ANYTHING ELSE
    node_t* it = swap_in->head;
    while (it->next != first) {
        it = it->next;
    }
    node_t* one = first;
    node_t* two = first->next;
    it->next = two;
    one->next = two->next;
    two->next = one;
}

void bubble_sort(linked_list_t* to_sort)
{
    int swapped = 0;
    node_t* last = NULL;
    do {
        swapped = 0;
        node_t* ptr = to_sort->head;
        while (ptr->next != last) {
            if (compare_void(to_sort, ptr)) {
                swap_address(to_sort, ptr);
                swapped = 1;
            } else {ptr = ptr->next;}
        }
        last = ptr;
    } while (swapped);
}