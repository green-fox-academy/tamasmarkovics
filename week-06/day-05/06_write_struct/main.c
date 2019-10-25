
#include <stdio.h>
#include <stdint.h>

/*
 * 1. Create a struct which represents a person:
 * - name (max 64 characters)
 * - age (integer)
 * - height in meters (floating point)
 */

typedef struct person {
    char name[64];
    int age;
    float height;
} person_t;

int main() {
    /*
     * 2. Create a person struct, fill it with some data and write it out to a binary file.
     *    Read it back to another struct variable and compare them. Are they equal?
     */

    person_t Joe = {"Joe", 33, 1.483f};

    FILE *fptr;
    if(!(fptr = fopen("../binary_Joe.bin", "wb"))) return -1;
    fwrite(&Joe, sizeof(person_t), 1, fptr);
    fclose(fptr);

    person_t is_this_Joe_questionmark;
    if(!(fptr = fopen("../binary_Joe.bin", "rb"))) return -1;
    fread(&is_this_Joe_questionmark, sizeof(person_t), 1, fptr);
    fclose(fptr);
    printf("name: %s ?= %s\nage: %d ?= %d\nheight: %f ?= %f\n", is_this_Joe_questionmark.name, Joe.name, is_this_Joe_questionmark.age, Joe.age, is_this_Joe_questionmark.height, Joe.height);

    /*
     * 3. Create an array which holds 10 person struct.
     *    Fill them with some data and write out the array to a binary file.
     *    Read it back to another array and compare the array content to the first one. Are they equal?
     */
    person_t Bob = {"Bob", 3, 1.083f};
    person_t Bill = {"Bill", 63, 1.583f};
    person_t Buck = {"Buck", 13, 1.283f};
    person_t Artur = {"Arturo", 75, 1.833f};

    person_t tavern[] = {Joe, Bob, Bill, Buck, Artur};
    if(!(fptr = fopen("../binary_people.bin", "wb"))) return -1;
    fwrite(tavern, sizeof(person_t), 5, fptr);
    fclose(fptr);

    person_t other_tavern[5];
    if(!(fptr = fopen("../binary_people.bin", "rb"))) return -1;
    fread(&other_tavern, sizeof(person_t), 5, fptr);
    fclose(fptr);

    printf("\nname: %s\nage: %d\nheight: %f\n", other_tavern[1].name, other_tavern[1].age, other_tavern[1].height);
    printf("\nname: %s\nage: %d\nheight: %f\n", other_tavern[2].name, other_tavern[2].age, other_tavern[2].height);

    return 0;
}