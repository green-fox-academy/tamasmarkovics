#ifndef INC_01_LINKED_LIST_LINKED_LIST_H
#define INC_01_LINKED_LIST_LINKED_LIST_H

#include <stdint.h>

enum data_type {
    INT,
    DOUBLE,
    FLOAT,
    CHAR
};

typedef struct node {
    void* data_ptr;
    struct node* next;
} node_t;

typedef struct linked_list {
    node_t* head;
    int size_of_data;
    enum data_type type_of_data;
} linked_list_t;


int get_data_size(enum data_type data);
linked_list_t* list_init(enum data_type type_of_data);
void push_back(linked_list_t* list, void* data);
void push_front(linked_list_t* list, void* data);
void init_head(linked_list_t* list, void* data);  //only utility
int get_size(linked_list_t* list);
void print_list(void (*func)(), linked_list_t* list);   //to be replaced, but fun!
void erase_at(linked_list_t* list, int at);
void delete(linked_list_t* list);
void empty(linked_list_t* list);
int search_list(linked_list_t* list, void* what);
void delete_all_value(linked_list_t* list, void* what);
void bubble_sort(linked_list_t* to_sort); //NOT WORKING ATM



void printer(linked_list_t* list, void* what);
void print_int(void* what);
void print_dbl(void* what);
void print_float(void* what);
void print_char(void* what);


void *print_functions[] = {
        print_int,
        print_dbl,
        print_float,
        print_char
};

#endif //INC_01_LINKED_LIST_LINKED_LIST_H

/*
TODO
Insert at the end               DONE
Insert at the beginning         DONE
Insert after                    DONE
Size                            DONE
Empty                           DONE
Delete                          DONE
Delete by value 💪              DONE
Search                          DONE
Implement bubble sort 💪
Implement insertion sort 💪
 */