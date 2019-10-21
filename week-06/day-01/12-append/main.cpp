#include <iostream>

void append_a(char *s);
int length_of_string(char *name);

int main() {
    // Create a program which asks for a string and stores it
    // Create a function which takes a string as a parameter and
    // appends a character 'a' to the end of it and returns the new string

    char str[255] = "";

        printf("Give me a string\n");
        scanf("%s", str);
        append_a(str);
        printf("%s\n", str);

    return 0;
}

void append_a(char *s)
{
    s[length_of_string(s)] = 'a';

}

int length_of_string(char *name)
{
    int length = 0;
    while (name[length] != '\0'){
        length++;
    }
    return length;
}