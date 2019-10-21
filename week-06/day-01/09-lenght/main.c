#include <stdio.h>

int lenght_of_string(char *name)
{
    int length = 0;
    while (name[length] != '\0'){
        length++;
    }
    return length;
}

int main() {
    // Create a program which asks for the name of the user and stores it
    // Create a function which takes a string as a parameter and returns the length of it
    // Solve this exercise with and without using string.h functions

    char name[30];
    name[0] = '\0';

    printf("Give me your name!\n");
    scanf("%s", name);

    printf("\nYour name is %d long.\n", lenght_of_string(name));


    return 0;
}