#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.
char* repeat_string(char* string, int repeat);

int main()
{
    char* repeated_string = repeat_string("More", 5);
    printf("%s\n", repeated_string);
    free(repeated_string);

    return 0;
}

char* repeat_string(char* string, int repeat)
{
    char *new = NULL;
    new = malloc(repeat * strlen(string) * sizeof(char) + 1);

    for (int i = 0; i < repeat; i++) {
        for (int j = 0; j < strlen(string); j++) {
            *(new + i * strlen(string) + j) = string[j];
        }
    }

    *(new + strlen(string) * repeat) = '\0';

    return new;
}