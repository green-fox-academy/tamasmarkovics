#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// the resulting array should be 20 elements long
// print the array in descending order
// delete the arrays after you don't use them

int main()
{
    int* arr1 = malloc(10 * sizeof(int));
    int* arr2 = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        *(arr1 + i) = 2 * i + 1;
        *(arr2 + i) = 2 * i;
    }

    arr1 = (int *)realloc(arr1, 20 * sizeof(int));

    for (int i = 0; i < 10; i++) {
        *(arr1 + 10 + i) = *(arr2 + i);
    }

    free(arr2);

    for (int i = 19; i >= 0; i--) {
        printf("%d, ", *(arr1 + i));
    }

    free(arr1);
    return 0;
}