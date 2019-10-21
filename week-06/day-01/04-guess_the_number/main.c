#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int to_guess = rand() % 20;
    int guess = 0;

    printf("Guess a number!\n");
    scanf("%d", &guess);
    while (guess != to_guess) {
        if (guess > to_guess) {
            printf("The number is lower!\n");
        } else printf("The number is higher!\n");
        printf("Guess a number\n");
        scanf("%d", &guess);
    }
    printf("%d is right!\n", guess);

    return 0;
}