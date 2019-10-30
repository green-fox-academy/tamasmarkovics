#ifndef INC_01_LINKED_LIST_LINKED_LIST_H
#define INC_01_LINKED_LIST_LINKED_LIST_H

typedef struct node {
    void* data_ptr;
    struct node* next;
} node_t;

typedef struct linked_list {
    node_t* head;
    int size_of_data;
} linked_list_t;


linked_list_t* list_init(int data_size);
void push_back(linked_list_t* list, void* data);
void push_front(linked_list_t* list, void* data);
void init_head(linked_list_t* list, void* data);
int get_size(linked_list_t* list);
void print_list(void (*func)(), linked_list_t* list);
#endif //INC_01_LINKED_LIST_LINKED_LIST_H