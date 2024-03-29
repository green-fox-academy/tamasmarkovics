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


//****  BASIC FUNCTIONS  ****//
int get_data_size(enum data_type type_of_data);
linked_list_t* list_init(enum data_type type_of_data);
void push_back(linked_list_t* push_in, void* data_to_push);
void push_front(linked_list_t* push_front_in, void* data_to_push);
void init_head(linked_list_t* to_init, void* head_data);  //only utility
int get_size(linked_list_t* get_size_of);
void erase_at(linked_list_t* erase_in, int at_index);
void delete_head(linked_list_t* to_delete);
void empty(linked_list_t* to_empty);
int search_list(linked_list_t* search_in, void* for_what);
void delete_all_by_value(linked_list_t* delete_in, void* what);
void bubble_sort(linked_list_t* to_sort);


//****  PRINT UTILITY  ****//
void print_list(linked_list_t* to_print);
void print_int(void* int_to_print);
void print_dbl(void* double_to_print);
void print_float(void* float_to_print);
void print_char(void* char_to_print);
void* get_printer(linked_list_t* list_to_print);

//****  COMPARE  ****//
int compare_void(linked_list_t* compare_in, node_t* first);
void* get_comparer(linked_list_t* compare_in);
int compare_int(node_t* first);
int compare_dbl(node_t* first);
int compare_float(node_t* first);
int compare_char(node_t* first);

//****  SWAP  ****//
void swap_address(linked_list_t* swap_in, node_t* first);

#endif //INC_01_LINKED_LIST_LINKED_LIST_H

/*
Insert at the end               DONE
Insert at the beginning         DONE
Insert after                    DONE
Size                            DONE
Empty                           DONE
Delete                          DONE
Delete by value 💪              DONE
Search                          DONE
Implement bubble sort 💪        DONE
TODO
Implement insertion sort 💪
 */