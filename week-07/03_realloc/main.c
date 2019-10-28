#include <stdio.h>
#include <stdlib.h>

// Please use the realloc function where applicable!
// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    printf("Give me a number!\n");
    int x = 0;
    scanf("%d", &x);

    int* pointer = NULL;
    pointer = (int*)realloc(pointer, x * sizeof(int));

    printf("Give me %d numbers!\n", x);
    for (int i = 0; i < x; i++) {
        scanf("%d", pointer + i);
    }
    printf("\n");

    int y = 0;
    for (int i = 0; i < x; i++) {
        y += *(pointer + i);
    }

    pointer = realloc(pointer, y * sizeof(int));
    for (int i = 0; i < y; i++) {
        *(pointer + i) = i;
    }

    for (int i = 1; i <= y; i++) {
        printf("%d, ", *(pointer + i));
    }

    pointer = realloc(pointer, 0);

    return 0;
}