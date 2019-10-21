#include <stdio.h>

int equal_sum(int num1, int num2);
int main()
{
    // Create a program which asks for two numbers and stores them
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of the number of digits are equal and 0 otherwise
    int numba1, numba2;
    printf("Give me 2 numbers!\n");
    scanf("%d%d", &numba1, &numba2);

    if (equal_sum(numba1, numba2)) {
        printf("sum of digits of %d and %d are equal!\n", numba1, numba2);
    } else printf("sum of digits of %d and %d are not equal!\n", numba1, numba2);

    return 0;
}

int equal_sum(int num1, int num2)
{
    int sum1 = 0, sum2 = 0;
    while (num1 == 0) {
        sum1 += num1 % 10;
        num1 /= 10;
    }
    while (num2 == 0) {
        sum2 += num2 % 10;
        num2 /= 10;
    }

    if (sum1 == sum2) {
        return 1;
    } else return 0;

}