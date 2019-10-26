#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct input {
    char group[5][10];
    int numbers[5][20];
    int no_of_numbers_per_group[5];
} input_t;


int main() {
    char* file_loc = "../median.txt";
    FILE *fptr;
    input_t structured_input;
    for (int z = 0; z < 5; z++) {
        structured_input.no_of_numbers_per_group[z] = 0;
        for (int s = 0; s < 20; s++) {
            structured_input.numbers[z][s] = 0;
        }
    }

    if(!(fptr = fopen(file_loc, "r"))) return -1;
    int i = 0;
    char tmp[100];
    while (fscanf(fptr, "%[^:]:%s\n", structured_input.group[i], tmp) == 2) {
        for (char *p = strtok(tmp, ","); p != NULL; p = strtok(NULL, ",")) {
            int next = atoi(p);
            structured_input.numbers[i][structured_input.no_of_numbers_per_group[i]] = next;

            structured_input.no_of_numbers_per_group[i]++;
        }
        i++;
    }

    for (int l = 0; l < 4; ++l) {
        printf("%s: ", structured_input.group[l]);
        for (int j = 0; j < structured_input.no_of_numbers_per_group[l]; ++j) {
            printf("%d,", structured_input.numbers[l][j]);
        }
        printf("\n");
    }
    for (int k = 0; k < 4; ++k) {
        for (int j = 0; j < structured_input.no_of_numbers_per_group[k] - 1; ++j) {
            for (int l = 0;  l < structured_input.no_of_numbers_per_group[k] - 1 - j; l++)
                if (structured_input.numbers[k][l] > structured_input.numbers[k][l+1]) {
                    int tempi = structured_input.numbers[k][l];
                    structured_input.numbers[k][l] = structured_input.numbers[k][l + 1];
                    structured_input.numbers[k][l + 1] = tempi;
                }
        }
    }

    printf("\nAFTER SORTING\n");
    for (int l = 0; l < 4; ++l) {
        printf("%s: %d ", structured_input.group[l], structured_input.no_of_numbers_per_group[l]);
        for (int j = 0; j < structured_input.no_of_numbers_per_group[l]; ++j) {
            printf("%d,", structured_input.numbers[l][j]);
        }
        printf("\n");
    }

    int index_of_min = 0;
    for (i = 1; i < 4; i++) {
        int index_med = structured_input.no_of_numbers_per_group[i - 1] / 2;
        int index_med1 = structured_input.no_of_numbers_per_group[i] / 2;

        if (structured_input.numbers[i][index_med1] < structured_input.numbers[i - 1][index_med]) index_of_min = i;
    }

    printf("%s has the lowest median\n", structured_input.group[index_of_min]);

    return 0;
}




