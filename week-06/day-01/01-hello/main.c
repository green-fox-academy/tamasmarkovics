#include <stdio.h>

int main()
{

    // Modify this program to greet you instead of the World!
    printf("Hello, you!\n");

    // Greet 3 of your classmates with this program, in three separate lines
    printf("Hello, Esther!\n");
    printf("Hello, Mary!\n");
    printf("Hello, Joe!\n");


    // Write a program that prints a few details to the terminal window about you
    // It should print each detail to a new line.
    //  - Your name
    //  - Your age
    //  - Your height in meters (as a decimal fraction)

    char name[] = "Tom";
    int age = 24;
    float height = 1.78f;

    printf("%s\n", name);
    printf("%d\n", age);
    printf("%0.2f\n", height);

    return 0;
}