#include <stdio.h>
#include <stdlib.h>

//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

int find_percentile(const int *elements, int size, int percentile);

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);

    int* arr = NULL;
    arr = malloc(x * y * sizeof(int));

    for (int i = 0; i < x * y; i++) {
        scanf("%d", (arr + i));
    }

    int percentile = find_percentile(arr, x * y, 50);

    printf("%d\n", percentile);

    return 0;
}


int find_percentile(const int *elements, int size, int percentile)
{
    int *ptr = NULL;
    ptr = malloc(sizeof(int) * size);
    for (int i = 0 ; i < size; i++) {
        *(ptr + i) = *(elements + i);
    }

    for (int j = 0; j < size; ++j) {
        for (int l = 0;  l < size - 1 - j; l++)
            if (ptr[l] > ptr[l+1]) {
                int temp_i = ptr[l];
                ptr[l] = ptr[l + 1];
                ptr[l + 1] = temp_i;
            }
    }

    int index = (int)(size * (percentile / 100.0));
    int return_val = ptr[index];
    free(ptr);

    return return_val;
}