#ifndef INC_02_BETTER_VECTOR_VECTOR_H
#define INC_02_BETTER_VECTOR_VECTOR_H

typedef struct vector {
    int size;
    int capacity;
    void* data;
    int elemet_size;
} vector_t;

void init_vector(vector_t* to_init, int init_capacity, int size_of_element);
void push_back(vector_t* to_push, void* new_int);
void* element_at(vector_t* in_at, int at);
void pop_back(vector_t* to_pop);
void destroy_vector(vector_t* to_destroy);
void vector_insert(vector_t* insert_in, int at, void* this);
int empty_vector(vector_t* to_empty);
void vector_erase(vector_t* erase_in, int at);
int search(vector_t* to_search, void* what);
void shuffle(vector_t* to_shuffle);
void element_swap(vector_t* swap_in, int this, int that);
void unique(vector_t* make_unique);
void transform(void (*func)(), vector_t* to_transform, int index, int num);

#endif //INC_02_BETTER_VECTOR_VECTOR_H


