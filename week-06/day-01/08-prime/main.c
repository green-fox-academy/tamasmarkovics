#include <stdio.h>
#include <math.h>

int is_it_prime(int prime)
{
    for (int i = 2; i <= sqrt(prime); i++) {
        if (prime % i == 0) return 0;
    }
    return 1;
}

int main() {
    printf("Give me a number!\n");
    int my_prime;
    scanf("%d", &my_prime);

    if (is_it_prime(my_prime)) {
        printf("\n%d is a prime\n", my_prime);
    } else printf("\n%d is not a prime\n", my_prime);
    return 0;
}