#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>


void init_vector(vector_t* to_init, int init_capacity, int size_of_element)
{
    if (init_capacity < 1 || size_of_element < 1) {
        to_init->error_handle = WRONG_ARGUMENT;
        return;
    }

    to_init->data = (void*)malloc(init_capacity * size_of_element);
    to_init->capacity = init_capacity;
    to_init->size = 0;
    to_init->element_size = size_of_element;
    to_init->error_handle = NO_ERROR;
}
void push_back(vector_t* to_push, void* new)
{
    if (to_push->size >= to_push->capacity) {
        to_push->capacity += 4 * to_push->size;
        to_push->data = (int *)realloc(to_push->data, to_push->capacity * to_push->element_size);
    }

    memcpy(&((char*)to_push->data)[to_push->size * to_push->element_size], (char*)new, to_push->element_size);
    to_push->size++;
}
void* element_at(vector_t* in_at, int at)
{
    if (at > in_at->size || at < 0) {
        in_at->error_handle = OUT_OF_BOUNDS;
        return (void*)(-1);
    }
    return (void*)&(((char*)(in_at->data))[at * in_at->element_size]);
}
void pop_back(vector_t* to_pop)
{
    if (to_pop->size == 0) {
        to_pop->error_handle = EMPTY;
        return;
    }

    to_pop->size--;

    if (to_pop->size < to_pop->capacity / 2) {
        to_pop->capacity /= 2;
        to_pop->data = (int *) realloc(to_pop->data, to_pop->capacity * to_pop->element_size);
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
    if (insert_in->size < at || at < 0) {
        insert_in->error_handle = OUT_OF_BOUNDS;
    }

    if (insert_in->size >= insert_in->capacity) {
        insert_in->capacity += 4 * insert_in->size;
        insert_in->data = realloc(insert_in->data, insert_in->capacity * insert_in->element_size);
    }

    for (int i = insert_in->size; i > at; i--) {
        memcpy(&(((char*)insert_in->data)[(i) * insert_in->element_size]), &(((char*)insert_in->data)[(i - 1) * insert_in->element_size]), insert_in->element_size);
    }

    memcpy(&((char*)insert_in->data)[at * insert_in->element_size], (char*)this, insert_in->element_size);
    insert_in->size++;
}
int empty_vector(vector_t* to_empty)
{
    for (int i = 0; i < to_empty->size * to_empty->element_size; i++) {
        ((char*)to_empty->data)[i] = '0';
    }

    for (int i = 0; i < to_empty->size * to_empty->element_size; i++) {
        if (((char*)to_empty->data)[i] != 0) {
            to_empty->size = 0;
            return 0;
        }
    }

    return 1;
}
void vector_erase(vector_t* erase_in, int at)
{
    if (erase_in->size < at || at < 0) {
        erase_in->error_handle = OUT_OF_BOUNDS;
    }

    for (int i = at; i < erase_in->size; i++) {
        memcpy(&(((char*)erase_in->data)[(i) * erase_in->element_size]), &(((char*)erase_in->data)[(i + 1) * erase_in->element_size]), erase_in->element_size);
    }

    erase_in->size--;
    if (erase_in->size < erase_in->capacity / 2) {
        erase_in->capacity /= 2;
        erase_in->data = (int *) realloc(erase_in->data, erase_in->capacity * erase_in->element_size);
    }
}
void vector_erase_multi(vector_t* erase_in, int at, int how_many)
{
    if (erase_in->size < at + how_many || at < 0 || how_many < 0) {
        erase_in->error_handle = OUT_OF_BOUNDS;
    }

    for (int i = at; i <= erase_in->size - how_many; i++) {
        memcpy(&(((char*)erase_in->data)[(i) * erase_in->element_size]), &(((char*)erase_in->data)[(i + how_many) * erase_in->element_size]), erase_in->element_size);
    }

    erase_in->size -= how_many;
    erase_in->capacity -= how_many / 2;
    erase_in->data = (int *) realloc(erase_in->data, erase_in->capacity * erase_in->element_size);
}
int search(vector_t* to_search, void* what)
{
    for (int i = 0; i < to_search->size; i++) {
        int found = 1;
        for (int j = 0; j < to_search->element_size; ++j) {
            if (((char*)to_search->data)[i * to_search->element_size + j]  != ((char*)what)[j]) {
                found = 0;
            }
        }
        if (found) return i;
    }

    return -1;
}
void element_swap(vector_t* swap_in, int this, int that)
{
    if (swap_in->size < this || this < 0 || swap_in->size < that || that < 0) {
        swap_in->error_handle = OUT_OF_BOUNDS;
    }

    char* temp = malloc(swap_in->element_size);
    memcpy(temp, &((char*)swap_in->data)[this * swap_in->element_size], swap_in->element_size);
    memcpy(&((char*)swap_in->data)[this * swap_in->element_size], &((char*)swap_in->data)[that * swap_in->element_size], swap_in->element_size);
    memcpy(&((char*)swap_in->data)[that * swap_in->element_size], temp, swap_in->element_size);
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
        //i-- is not necessary, because of the backward iteration
        if (index != -1 && index != i) vector_erase(make_unique, index);
    }
}
void transform(void (*func)(), vector_t* to_transform, int index, int num)
{
    func(to_transform, index);
}