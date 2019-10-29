#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

void init_vector(vector_t* to_init, int init_capacity)
{
    to_init->data = (int *) calloc(init_capacity, sizeof(int));
    to_init->capacity = init_capacity;
    to_init->size = 0;
}

void push_back(vector_t* to_push, int new_int)
{
    if (to_push->size >= to_push->capacity) {
        to_push->capacity += 4;
        to_push->data = (int *) realloc(to_push->data, to_push->capacity * sizeof(int));
    }
    to_push->data[to_push->size] = new_int;
    to_push->size++;
}

void insert_at(vector_t* to_insert, int at, int new_int)
{
    if (to_insert->size >= to_insert->capacity) {
        to_insert->capacity += 4;
        to_insert->data = (int *) realloc(to_insert->data, to_insert->capacity * sizeof(int));
    }
    for (int i = to_insert->size; i > at; i++) {

    }
}

int element_at(vector_t* in_at, int at)
{
    return in_at->data[at];
}

void pop_back(vector_t* to_pop)
{
    to_pop->size--;
    if (to_pop->size < to_pop->capacity / 2) {
        to_pop->capacity /= 2;
        to_pop->data = (int *) realloc(to_pop->data, to_pop->capacity * sizeof(int));
    }
}


void destroy_vector(vector_t* to_destroy)
{
    to_destroy->size = 0;
    to_destroy->capacity = 0;
    free(to_destroy->data);
}
