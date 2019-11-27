#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct film {
    char* name;
    long long income;
    int year;
} film_t;

int get_size();
film_t* fill_struct();



int main()
{
    film_t* stats = fill_struct();
    for (int i = 0; i < get_size(); i++) {
        printf("%s\t%lld\t%d\n", stats[i].name, stats[i].income, stats[i].year);
    }
    return 0;
}

int get_size()
{
    FILE *fptr;
    if (!(fptr = fopen("../movies.txt", "r"))) return -1;
    int row_count = 0;
    char tmp_name[100];
    char tmp_income[20];
    char tmp_year[6];
    while (fscanf(fptr, " %[^$]%*c%s %[^\n] ", tmp_name, tmp_income, tmp_year) == 3) {
        row_count++;
    }
    fclose(fptr);
    return row_count;
}

film_t* fill_struct()
{
    film_t* temp_stats;

    FILE *fptr;
    if (!(fptr = fopen("../movies.txt", "r"))) return NULL;

    char tmp_name[100];
    char tmp_income[20];
    char tmp_year[6];

    int index = 0;
    temp_stats = malloc(get_size() * sizeof(film_t));
    while (fscanf(fptr, " %[^$]%*c%s %[^\n] ", tmp_name, tmp_income, tmp_year) == 3) {
        temp_stats[index].name = malloc((strlen(tmp_name) + 1) * sizeof(char));
        memcpy(temp_stats[index].name, tmp_name, strlen(tmp_name) + 1);
        temp_stats[index].year = atoi(tmp_year);
        long long money = 0;
        for (char *p = strtok(tmp_income, ","); p != NULL; p = strtok(NULL, ",")) {
            money *= 1000;
            money += atol(p);
        }
        temp_stats[index].income = money;
        index++;
    }
    fclose(fptr);
    return temp_stats;
}