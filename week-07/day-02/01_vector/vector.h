#ifndef INC_01_VECTOR_VECTOR_H
#define INC_01_VECTOR_VECTOR_H

typedef struct vector {
    int size;
    int capacity;
    int* data;
} vector_t;

void init_vector(vector_t* to_init, int init_capacity);
void push_back(vector_t* to_push, int new_int);
void insert_at(vector_t* to_insert, int at, int new_int);
int element_at(vector_t* in_at, int at);
void pop_back(vector_t* to_pop);
void destroy_vector(vector_t* to_destroy);

#endif //INC_01_VECTOR_VECTOR_H
