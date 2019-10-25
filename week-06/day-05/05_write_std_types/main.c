#include <stdio.h>


int main() {
    //NAMES WERE GIVEN, NOT MY FAULT!!!!!!!
    int myInt = 123456789;
    float myFloat = 3.14159265359F;
    char myChar = 'c';

    //NAMES WERE GIVEN, NOT MY FAULT!!!!!!!
    int myIntRead;
    float myFloatRead;
    char myCharRead;

    //1. Write out myInt to myInt.txt as a text!
    FILE *fptr;
    if (!(fptr = fopen("../myInt.txt", "wb"))) return -1;
    fprintf(fptr, "%d", myInt);
    fclose(fptr);

    //2. Write out myInt to myInt.bin as a binary file!
    //   Check the size of myInt.txt and myInt.bin! Why it is different?
    if(!(fptr = fopen("../myInt.bin", "wb"))) return -1;
    fwrite(&myInt, sizeof(int), 1, fptr);
    fclose(fptr);

    //3. Write out myFloat to myFloat.bin
    if(!(fptr = fopen("../myFloat.bin", "wb"))) return -1;
    fwrite(&myFloat, sizeof(float), 1, fptr);
    fclose(fptr);

    // and myChar to myChar.bin!
    if(!(fptr = fopen("../myChar.bin", "wb"))) return -1;
    fwrite(&myChar, sizeof(char), 1, fptr);
    fclose(fptr);

    //4. Read them back to myIntRead
    if(!(fptr = fopen("../myInt.bin", "rb"))) return -1;
    fread(&myIntRead, sizeof(int), 1, fptr);
    fclose(fptr);
    printf("%d\n", myIntRead);

    // , myFloatRead
    if(!(fptr = fopen("../myFloat.bin", "rb"))) return -1;
    fread(&myFloatRead, sizeof(float), 1, fptr);
    fclose(fptr);
    printf("%f\n", myFloatRead);

    // and myCharRead and compare these variables to myInt, myFloat, myChar,
    if(!(fptr = fopen("../myChar.bin", "rb"))) return -1;
    fread(&myCharRead, sizeof(char), 1, fptr);
    fclose(fptr);
    printf("%c\n", myCharRead);
    //   they should be the same.
    //they are!


    return 0;
}