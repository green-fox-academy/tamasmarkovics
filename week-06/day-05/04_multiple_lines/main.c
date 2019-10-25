#include <stdio.h>
#include <string.h>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

void write_multi_lines (char *path, char *word, int repetition)
{
    FILE *fptr;
    if (!(fptr = fopen(path, "w"))) printf("so that didnt work");

    fprintf(fptr, "%s", word);
    for (int i = 0; i < repetition - 1; ++i) {
        fprintf(fptr, "\n%s", word);
    }

    fclose(fptr);
}

int main()
{
    char file_path[] = "../my-file.txt";
    char to_file[] = "i will fall asleeeeeep soon dododooo";
    write_multi_lines(file_path, to_file, 5);

    return 0;
}