#include <stdio.h>
#include "linked_list.h"



int main()
{
    linked_list_t* ints = list_init(INT);
    for (int i = 1; i <= 5; i++) {
        int temp_int = 11 * i;
        push_back(ints, &temp_int);
    }
    printf("\nPrinting ints!\n");
    print_list(ints);
    printf("\n");

    linked_list_t* doubles = list_init(DOUBLE);
    for (int i = 1; i <= 5; i++) {
        double temp_dbl = 11.11 * i;
        push_back(doubles, &temp_dbl);
    }
    printf("\nPrinting doubles!\n");
    print_list(doubles);
    printf("\n");

    linked_list_t* floats = list_init(FLOAT);
    for (int i = 1; i <= 5; i++) {
        float temp_float = 11.11f * (float)i;
        push_back(floats, &temp_float);
    }
    printf("\nPrinting floats!\n");
    print_list(floats);
    printf("\n");

    linked_list_t* chars = list_init(CHAR);
    for (int i = 1; i <= 5; i++) {
        int temp_char = 'a' + i;
        push_back(chars, &temp_char);
    }
    printf("\nPrinting characters!\n");
    print_list(chars);
    printf("\n");


    return 0;
}