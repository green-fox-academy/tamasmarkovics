#include <stdio.h>
#include <string.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main ()
{
    FILE *fptr;
    if (!(fptr = fopen("my-file.txt", "r"))) return -1;

    char line[100];
    while (fgets (line , 100 , fptr)) {
        printf ("%s", line);
    }

    fclose(fptr);

    return 0;
}