#include <stdio.h>

int where_is_it(char c, char *s);

int main() {
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    // Case 1:
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    // Case 2:
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //
    printf("Give me a char and a string to search in\n");
    char to_find = '@';
    char find_in[30];
    find_in[0] = '\0';

    scanf("%c%s", &to_find, &find_in);

    printf("%d", where_is_it(to_find, find_in));

    return 0;
}


int where_is_it(char c, char *s)
{
    int i = 0;
    while (s[i] != '\0'){
        if (s[i] == c) {
            return i;
        }
        else i++;
    }
    return -1;
}