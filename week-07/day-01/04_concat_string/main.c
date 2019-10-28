#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

char* concat_string (char* first, char* second);

int main()
{
    char* str1 = "kecske";
    char* str2 = "sajt";
    char *result = concat_string(str1, str2);
    printf("%s\n", result);
    free(result);
    return 0;
}


char* concat_string (char* first, char* second)
{
    char *new = NULL;
    new = realloc(new, strlen(first) + strlen(second) + 1);
    for (int i = 0; i < strlen(first); i++) {
        *(new + i) = first[i];
    }

    for (int i = 0; i <= strlen(second); i++) {
        *(new + strlen(first) + i) = second[i];
    }
    return new;
}