#include <stdio.h>
#include "vector.h"

int main()
{
    vector_t test;
    init_vector(&test, 10, sizeof(float));
    float td = 32.5678f;
    float asd = 62.5678f;
    push_back(&test, (void*)&td);
    push_back(&test, (void*)&td);
    push_back(&test, (void*)&td);
    push_back(&test, (void*)&asd);
    push_back(&test, (void*)&td);
    td = 33.44f;
    push_back(&test, (void*)&asd);
    push_back(&test, (void*)&td);
    push_back(&test, (void*)&td);

    for (int i = 0; i < test.size; ++i) {
        printf("%.2f, ", *(float*)element_at(&test, i));
    }
    printf("\n");
    float my_insert = 69.6969f;
    vector_insert(&test, 2, &my_insert);
    my_insert = 44.1f;
    vector_insert(&test, 2, &my_insert);
    my_insert = 141.1f;
    vector_insert(&test, 2, &my_insert);
    pop_back(&test);

    for (int i = 0; i < test.size; ++i) {
        printf("%.2f, ", *(float*)element_at(&test, i));
    }
    printf("\n");
    vector_erase(&test, 4);

    for (int i = 0; i < test.size; ++i) {
        printf("%.2f, ", *(float*)element_at(&test, i));
    }

    destroy_vector(&test);


    return 0;
}