#include <stdio.h>
#include "linked_list.h"


int main() {

    linked_list_t* my_list = list_init(sizeof(double));
    double temp = 44.44;
    push_back(my_list, &temp);
    temp = 69.69;
    push_back(my_list, &temp);
    temp = 88.44;
    push_back(my_list, &temp);
    printf("%lf\n", *(double *)my_list->head->data_ptr);
    printf("%lf\n", *(double *)my_list->head->next->data_ptr);
    printf("%lf\n", *(double *)my_list->head->next->next->data_ptr);
    return 0;
}