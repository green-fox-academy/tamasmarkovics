#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

void init_vector(vector_t* to_init, int init_capacity, int size_of_element)
{
    to_init->data = (void*)malloc(init_capacity * size_of_element);
    to_init->capacity = init_capacity;
    to_init->size = 0;
    to_init->elemet_size = size_of_element;
}

void push_back(vector_t* to_push, void* new)
{
    if (to_push->size >= to_push->capacity) {
        to_push->capacity += 4 * to_push->size;
        to_push->data = (int *)realloc(to_push->data, to_push->capacity * to_push->elemet_size);
    }

    memcpy(&((char*)to_push->data)[to_push->size * to_push->elemet_size], (char*)new, to_push->elemet_size);
    to_push->size++;
}

void* element_at(vector_t* in_at, int at)
{
    return (void*)&(((char*)(in_at->data))[at * in_at->elemet_size]);
}

void pop_back(vector_t* to_pop)
{
    to_pop->size--;
    if (to_pop->size < to_pop->capacity / 2) {
        to_pop->capacity /= 2;
        to_pop->data = (int *) realloc(to_pop->data, to_pop->capacity * to_pop->elemet_size);
    }
}

void destroy_vector(vector_t* to_destroy)
{
    to_destroy->size = 0;
    to_destroy->capacity = 0;
    free(to_destroy->data);
}

void vector_insert(vector_t* insert_in, int at, void* this)
{
    if (insert_in->size >= insert_in->capacity) {
        insert_in->capacity += 4 * insert_in->size;
        insert_in->data = realloc(insert_in->data, insert_in->capacity * insert_in->elemet_size);
    }

    for (int i = insert_in->size; i > at; i--) {
        memcpy(&(((char*)insert_in->data)[(i) * insert_in->elemet_size]), &(((char*)insert_in->data)[(i - 1) * insert_in->elemet_size]), insert_in->elemet_size);
    }
    memcpy(&((char*)insert_in->data)[at * insert_in->elemet_size], (char*)this, insert_in->elemet_size);
    insert_in->size++;
}

int empty_vector(vector_t* to_empty)
{
    for (int i = 0; i < to_empty->size * to_empty->elemet_size; i++) {
        ((char*)to_empty->data)[i] = '0';
    }
    for (int i = 0; i < to_empty->size * to_empty->elemet_size; i++) {
        if (((char*)to_empty->data)[i] != 0) {
            to_empty->size = 0;
            return 0;
        }
    }
    return 1;
}

void vector_erase(vector_t* erase_in, int at)
{
    for (int i = at; i < erase_in->size; i++) {
        memcpy(&(((char*)erase_in->data)[(i) * erase_in->elemet_size]), &(((char*)erase_in->data)[(i + 1) * erase_in->elemet_size]), erase_in->elemet_size);
    }
    erase_in->size--;
}


int search(vector_t* to_search, void* what)
{
    for (int i = 0; i < to_search->size; i++) {
        int found = 1;
        for (int j = 0; j < to_search->elemet_size; ++j) {
            if (((char*)to_search->data)[i * to_search->elemet_size + j]  != ((char*)what)[j]) {
                found = 0;
            }
        }
        if (found) return i;
    }
    return -1;
}

void element_swap(vector_t* swap_in, int this, int that)
{
    char* temp = malloc(swap_in->elemet_size);
    memcpy(temp, &((char*)swap_in->data)[this * swap_in->elemet_size], swap_in->elemet_size);
    memcpy(&((char*)swap_in->data)[this * swap_in->elemet_size], &((char*)swap_in->data)[that * swap_in->elemet_size], swap_in->elemet_size);
    memcpy(&((char*)swap_in->data)[that * swap_in->elemet_size], temp, swap_in->elemet_size);
    free(temp);
}

void shuffle(vector_t* to_shuffle)
{
    srand(time(NULL));
    for (int i = 0; i < to_shuffle->size; ++i) {
        element_swap(to_shuffle, i, rand() % to_shuffle->size);
    }
}

void unique(vector_t* make_unique) {
    for (int i = make_unique->size - 1; i >= 0; --i) {
        int index = search(make_unique, element_at(make_unique, i));
        if (index != -1 && index != i) vector_erase(make_unique, index);
    }
}
