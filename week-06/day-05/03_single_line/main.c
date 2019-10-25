
#include <stdio.h>
#include <string.h>

// Open a file called "my-file.txt"
// Write your name in it as a single line

int main ()
{
    FILE *fptr;
    if (!(fptr = fopen("../my-file.txt", "w"))) return -1;

    fprintf(fptr, "i will fall asleeeeeep soon sadface");

    fclose(fptr);
    return 0;
}