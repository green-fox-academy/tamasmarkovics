#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file

int main ()
{
    FILE *fptr;
    if (!(fptr = fopen("../my-file.txt", "r"))) return -1;

    int count = 0;
    char line[100];
    while (fgets (line , 100 , fptr)) {
        count++;
    }
    fclose(fptr);

    printf ("%d", count);


    return 0;
}


