#include <stdio.h>
#include "linked_list.h"

void print_double(void* to_print)
{
    printf("%lf", *(double*)to_print);
}


int main() {

    linked_list_t* my_list = list_init(sizeof(double));
    double temp = 44.44;
    push_front(my_list, &temp);
    temp = 11.43;
    push_back(my_list, &temp);
    temp = 69.69;
    push_back(my_list, &temp);
    temp = 88.44;
    push_back(my_list, &temp);

    print_list(print_double, my_list);
    printf("Size: %d\n", get_size(my_list));

    push_front(my_list, &temp);

    print_list(print_double, my_list);
    printf("Size: %d\n", get_size(my_list));


    return 0;
}