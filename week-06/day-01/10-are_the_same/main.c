#include <stdio.h>
#include <stdlib.h>

int are_the_same(char *s1, char *s2);
int length_of_string(char *name);

int main() {
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.
    printf("Give me two strings to compare!\n");

    char str1[30];
    char str2[30];
    scanf("%s%s", str1, str2);

    printf("\n%d\n", are_the_same(str1, str2));

    return 0;
}

int are_the_same(char *s1, char *s2)
{
    if (length_of_string(s1) != length_of_string(s2)) return 0;
    for (int i = 0; i < length_of_string(s1); i++) {
        if (s1[i] == s2[i]) {}
        else if (abs((int)s1[i] - (int)s2[i]) != 32) return 0;
    }
    return 1;
}

int length_of_string(char *name)
{
    int length = 0;
    while (name[length] != '\0'){
        length++;
    }
    return length;
}
