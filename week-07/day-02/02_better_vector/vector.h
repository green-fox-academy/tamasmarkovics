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

#endif //INC_02_BETTER_VECTOR_VECTOR_H

/*
TODO
Search within the vector
This function should take a vector and a value as parameters. It should look for a given value in the specificed vector and return the index where it's found. If the element is not found it should return -1.

Shuffle 💪
It should randomly rearrange all the elements in the vector.

Unique 💪
It should remove the duplicate elements from the vector

Transform 💪 💪 💪
This function should take a vector and a function as parameter. It should apply this function to all the elements in the vector.
*/

