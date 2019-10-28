#include <stdio.h>
#include <stdlib.h>


int main()
{
    int* pointer = NULL;
    // with malloc
    // please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
    // please delete the array before the program exits

    pointer = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        *(pointer + i) = i;
    }

    printf("\nWith malloc:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d, ", *(pointer + i));
    }

    free(pointer);

    // with calloc
    // please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
    // please delete the array before the program exits
    // what's the difference between this and the previous exercise?

    pointer = (int *)calloc(10, sizeof(int));
    for (int i = 0; i < 5; i++) {
        *(pointer + i) = 5;
    }
    printf("\nWith calloc:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d, ", *(pointer + i));
    }

    //free(pointer);
    //SAME AS
    realloc(pointer, 0);

    return 0;
}