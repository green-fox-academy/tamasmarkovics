#include <stdio.h>
#include "linked_list.h"

void print_double(void* to_print)
{
    printf("%lf", *(double*)to_print);
}


int main()
{
    linked_list_t* my_list = list_init(DOUBLE);
    double temp = 44.44;
    push_front(my_list, &temp);
    temp = 511.43;
    push_back(my_list, &temp);
    double asd = 2132.321;
    push_back(my_list, &asd);
    temp = 88.44;
    push_back(my_list, &temp);
    push_back(my_list, &temp);
    push_back(my_list, &temp);
    push_back(my_list, &temp);
    push_back(my_list, &temp);
    temp = 33.44;
    push_back(my_list, &temp);
    push_front(my_list, &temp);
    push_front(my_list, &temp);
    push_front(my_list, &temp);
    push_front(my_list, &temp);

    print_list(print_double, my_list);
    printf("Size: %d\n", get_size(my_list));
    erase_at(my_list, 12);

    delete_all_value(my_list, &temp);
    print_list(print_double, my_list);
    printf("Size: %d\n", get_size(my_list));

    push_front(my_list, &temp);
    asd = 2132.321;

    print_list(print_double, my_list);
    printf("Size: %d\n", get_size(my_list));

    print_list(print_double, my_list);
    printf("Size: %d\n", get_size(my_list));
    printf("%lf is at %d\n", asd, search_list(my_list, &asd));
    temp = 2;
    push_front(my_list, &temp);
    print_list(print_double, my_list);
    //bubble_sort(my_list);
    print_list(print_double, my_list);
    delete(my_list);
    print_list(print_double, my_list);
    printf("Size: %d\n", get_size(my_list));
    empty(my_list);
    printf("Size: %d\n", get_size(my_list));
    return 0;
}