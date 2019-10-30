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
void init_head(linked_list_t* list, void* data);  //only utility
int get_size(linked_list_t* list);
void print_list(void (*func)(), linked_list_t* list);
void erase_at(linked_list_t* list, int at);
void delete(linked_list_t* list);
void empty(linked_list_t* list);
int search_list(linked_list_t* list, void* what);
void delete_all_value(linked_list_t* list, void* what);

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