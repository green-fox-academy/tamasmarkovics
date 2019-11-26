#include <stdio.h>
#include "linked_list.h"



int main()
{
    linked_list_t* ints = list_init(INT);
    for (int i = 10; i >= 1; i--) {
        int temp_int = 11 * i;
        push_back(ints, &temp_int);
    }
    for (int i = 1; i <= 10; i++) {
        int temp_int = 2 * i;
        push_back(ints, &temp_int);
    }
    for (int i = 1; i <= 10; i++) {
        int temp_int = 2 * i + 1;
        push_back(ints, &temp_int);
    }
    printf("\nPrinting ints!\n");
    print_list(ints);
    bubble_sort(ints);
    printf("Bubble sorting ints!\n");
    print_list(ints);
    printf("\n");


    linked_list_t* doubles = list_init(DOUBLE);
    for (int i = 1; i <= 5; i++) {
        double temp_dbl = 11.11 * i;
        push_back(doubles, &temp_dbl);
    }

    for (int i = 10; i >= 0; i--) {
        double temp_dbl = 1.11 * i;
        push_back(doubles, &temp_dbl);
    }
    printf("\nPrinting doubles!\n");
    print_list(doubles);
    bubble_sort(doubles);
    printf("Bubble sorting doubles!\n");
    print_list(doubles);
    printf("\n");


    linked_list_t* floats = list_init(FLOAT);
    for (int i = 10; i >= 0; i--) {
        float temp_float = 11.11f * (float)i;
        push_back(floats, &temp_float);
    }
    for (int i = 0; i <= 10; i++) {
        float temp_float = 5.11f * (float)i;
        push_back(floats, &temp_float);
    }
    printf("\nPrinting floats!\n");
    print_list(floats);
    bubble_sort(floats);
    printf("Bubble sorting floats!\n");
    print_list(floats);
    printf("\n");

    linked_list_t* chars = list_init(CHAR);
    for (int i = 0; i <= 10; i++) {
        int temp_char = 'k' + i;
        push_back(chars, &temp_char);
    }
    for (int i = 0; i <= 10; i++) {
        int temp_char = 'a' + i;
        push_back(chars, &temp_char);
    }
    printf("\nPrinting characters!\n");
    print_list(chars);
    bubble_sort(chars);
    printf("Bubble sorting characters!\n");
    print_list(chars);
    printf("\n");


    return 0;
}