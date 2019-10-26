#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct input {
    char group_name[4][10];
    int numbers_in_group[4][20];
    int no_of_numbers_per_group[4];
} input_t;

void clear_struct(input_t *to_clear);                   //fills numbers_in_group and no_of_numbers_per_group with 0s
void sort_struct(input_t *to_sort);                     //sorts numbers_in_group to ascending order
int read_to_struct(input_t *to_fill, char* file_path);  //fills the struct from given input file
void find_min_median_in(input_t find_median);           //finds and prints out the group with minimum median
//print_struct only for testing purposes
void print_struct(input_t to_print);                    //prints out struct in <group_name>: int, int, int... format


int main()
{
    char* file_loc = "../median.txt";
    input_t structured_input;
    clear_struct(&structured_input);

    if (read_to_struct(&structured_input, file_loc) == -1) {
        printf("There was a problem with the input file!");
        return -1;
    }
    print_struct(structured_input);

    sort_struct(&structured_input);
    printf("\nAFTER SORTING\n");
    print_struct(structured_input);

    find_min_median_in(structured_input);

    return 0;
}


void print_struct(input_t to_print)
{
    for (int i = 0; i < 4; ++i) {
        printf("%s: %d", to_print.group_name[i], to_print.numbers_in_group[i][0]);
        for (int j = 1; j < to_print.no_of_numbers_per_group[i]; ++j) {
            printf(",%d", to_print.numbers_in_group[i][j]);
        }
        printf("\n");
    }
}

void clear_struct(input_t *to_clear)
{
    for (int i = 0; i < 4; i++) {
        to_clear->no_of_numbers_per_group[i] = 0;
        for (int j = 0; j < 20; j++) {
            to_clear->numbers_in_group[i][j] = 0;
        }
    }
}

void sort_struct(input_t *to_sort)
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < to_sort->no_of_numbers_per_group[i] - 1; ++j) {
            for (int l = 0;  l < to_sort->no_of_numbers_per_group[i] - 1 - j; l++)
                if (to_sort->numbers_in_group[i][l] > to_sort->numbers_in_group[i][l+1]) {
                    int temp_i = to_sort->numbers_in_group[i][l];
                    to_sort->numbers_in_group[i][l] = to_sort->numbers_in_group[i][l + 1];
                    to_sort->numbers_in_group[i][l + 1] = temp_i;
                }
        }
    }
}

int read_to_struct(input_t *to_fill, char* file_path)
{
    char tmp[100];
    FILE *fptr;
    if(!(fptr = fopen(file_path, "r"))) return -1;

    int i = 0;
    while (fscanf(fptr, "%[^:]:%s\n", to_fill->group_name[i], tmp) == 2) {
        for (char *p = strtok(tmp, ","); p != NULL; p = strtok(NULL, ",")) {
            int next = atoi(p);
            to_fill->numbers_in_group[i][to_fill->no_of_numbers_per_group[i]] = next;
            to_fill->no_of_numbers_per_group[i]++;
        }
        i++;
    }

    fclose(fptr);
    return 0;
}

void find_min_median_in(input_t find_median_in)
{
    int index_of_min = 0;
    for (int i = 1; i < 4; i++) {
        int med = find_median_in.no_of_numbers_per_group[i - 1] / 2;
        int med1 = find_median_in.no_of_numbers_per_group[i] / 2;
        if (find_median_in.numbers_in_group[i][med1] < find_median_in.numbers_in_group[i - 1][med]) index_of_min = i;
    }
    printf("\n%s has the lowest median!\n", find_median_in.group_name[index_of_min]);
}