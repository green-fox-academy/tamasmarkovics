#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct film {
    char* name;
    long long income;
    int year;
} film_t;

typedef struct yearly_inc {
    int year;
    long long income;
} yearly_inc_t;

int get_size();
film_t* fill_struct();
int get_unique_year(film_t* stat);
yearly_inc_t* get_yearly_stat(film_t* stat);
int getbestyear(yearly_inc_t* yearly, int years);

int main()
{
    film_t* stats = fill_struct();
    for (int i = 0; i < get_size(); i++) {
        printf("%s\t%lld\t%d\n", stats[i].name, stats[i].income, stats[i].year);
    }

    yearly_inc_t* yearly_stats = get_yearly_stat(stats);
    for (int k = 0; k < get_unique_year(stats); ++k) {
        printf("%d %lld\n", yearly_stats[k].year, yearly_stats[k].income);
    }

    printf("The best year was %d\n", getbestyear(yearly_stats, get_unique_year(stats)));

    for (int j = 0; j < get_size(); ++j) {
        free(stats[j].name);
    }
    free(stats);
    free(yearly_stats);
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

int get_unique_year(film_t* stat)
{
    int sum = 0;
    for (int i = 0; i < get_size(); i++) {
        int match = 0;
        for (int j = 0; j < i; j++) {
            if (stat[i].year == stat[j].year) {
                match++;
            }
        }
        if (match == 0) {
            sum++;
        }
    }
    return sum;
}

yearly_inc_t* get_yearly_stat(film_t* stat)
{
    int num = get_unique_year(stat);
    yearly_inc_t* yearly_stat = calloc(num, sizeof(yearly_inc_t));
    int years = 0;
    for (int i = 0; i < get_size(); ++i) {
        int found = 0;
        for (int j = 0; j < years && !found; ++j) {
            if (stat[i].year == yearly_stat[j].year) {
                yearly_stat[j].income += stat[i].income;
                found++;
            }
        }
        if (!found) {
            yearly_stat[years].year = stat[i].year;
            yearly_stat[years].income = stat[i].income;
            years++;
        }
    }
    return yearly_stat;
}

int getbestyear(yearly_inc_t* yearly, int years)
{
    long long max = 0;
    int year = 0;
    for (int i = 0; i < years; ++i) {
        if (max < yearly[i].income) {
            max = yearly[i].income;
            year = yearly[i].year;
        }
    }

    return year;
}
