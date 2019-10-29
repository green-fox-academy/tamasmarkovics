#include <stdio.h>
#include "vector.h"

int main()
{
    vector_t test;
    init_vector(&test, 10, sizeof(int));
    int td = 32;
    int asd = 62;
    push_back(&test, (void*)&td);
    push_back(&test, (void*)&td);
    push_back(&test, (void*)&td);
    push_back(&test, (void*)&asd);
    push_back(&test, (void*)&td);
    td = 33;
    push_back(&test, (void*)&asd);
    push_back(&test, (void*)&td);
    push_back(&test, (void*)&td);

    for (int i = 0; i < test.size; ++i) {
        printf("%d, ", *(int*)element_at(&test, i));
    }
    printf("\n");
    int my_insert = 69;
    vector_insert(&test, 2, &my_insert);
    my_insert = 44;
    vector_insert(&test, 2, &my_insert);
    my_insert = 141;
    vector_insert(&test, 2, &my_insert);

    pop_back(&test);

    for (int i = 0; i < test.size; ++i) {
        printf("%d, ", *(int*)element_at(&test, i));
    }
    printf("\nDelete 4\n");
    vector_erase(&test, 4);

    for (int i = 0; i < test.size; ++i) {
        printf("%d, ", *(int *)element_at(&test, i));
    }

    int temp = 141;
    printf("\n%d is at %d", temp, search(&test, &temp));


    printf("\nSwap 3 & 5\n");
    element_swap(&test, 3, 5);
    for (int i = 0; i < test.size; ++i) {
        printf("%d, ", *(int *)element_at(&test, i));
    }
    printf("\nShuffle\n");
    shuffle(&test);
    for (int i = 0; i < test.size; ++i) {
        printf("%d, ", *(int *)element_at(&test, i));
    }

    printf("\nMake unique\n");
    unique(&test);
    for (int i = 0; i < test.size; ++i) {
        printf("%d, ", *(int *)element_at(&test, i));
    }

    transform(vector_insert, &test, 4, 992);
    printf("\nShuffle\n");
    for (int i = 0; i < test.size; ++i) {
        printf("%d, ", *(int *)element_at(&test, i));
    }
    destroy_vector(&test);
    return 0;
}