#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct film {
    char* name;
    long long income;
    int year;
} film_t;

typedef struct yearly_income {
    int year;
    long long income;
} yearly_income_t;

int get_movies_number();
film_t* order_data();
int get_unique_year(film_t* statistics);
yearly_income_t* get_yearly_stat(film_t* statistics);
int get_best_year(yearly_income_t* yearly_statistics, int years);

int main()
{
    film_t* stats = order_data();

    //for (int i = 0; i < get_movies_number(); i++) {
    //    printf("%s\t%lld\t%d\n", stats[i].name, stats[i].income, stats[i].year);
    //}

    yearly_income_t* yearly_stats = get_yearly_stat(stats);
    printf("Yearly income statistics:\n");
    for (int k = 0; k < get_unique_year(stats); ++k) {
        printf("%d $%lld\n", yearly_stats[k].year, yearly_stats[k].income);
    }

    printf("The best year was %d\n", get_best_year(yearly_stats, get_unique_year(stats)));

    for (int j = 0; j < get_movies_number(); ++j) {
        free(stats[j].name);
    }
    free(stats);
    free(yearly_stats);
    return 0;
}

int get_movies_number()
{
    FILE *fptr;
    if (!(fptr = fopen("../movies.txt", "r"))) return -1;

    int row_count = 0;
    char tmp_name[100];
    char tmp_income[25];
    char tmp_year[6];

    while (fscanf(fptr, " %[^$]%*c%s %[^\n] ", tmp_name, tmp_income, tmp_year) == 3) {
        row_count++;
    }

    fclose(fptr);

    return row_count;
}

film_t* order_data()
{
    film_t* temp_stats;

    FILE *fptr;
    if (!(fptr = fopen("../movies.txt", "r"))) return NULL;

    char tmp_name[100];
    char tmp_income[20];
    char tmp_year[6];

    int index = 0;
    temp_stats = malloc(get_movies_number() * sizeof(film_t));

    while (fscanf(fptr, " %[^$]%*c%s %[^\n] ", tmp_name, tmp_income, tmp_year) == 3) {
        temp_stats[index].name = malloc((strlen(tmp_name) + 1) * sizeof(char));
        memcpy(temp_stats[index].name, tmp_name, strlen(tmp_name) + 1);
        temp_stats[index].year = atoi(tmp_year);

        long long tmp_money = 0;
        for (char *p = strtok(tmp_income, ","); p != NULL; p = strtok(NULL, ",")) {
            tmp_money *= 1000;
            tmp_money += atol(p);
        }

        temp_stats[index].income = tmp_money;
        index++;
    }
    fclose(fptr);
    return temp_stats;
}

int get_unique_year(film_t* statistics)
{
    int diff_years = 0;
    for (int i = 0; i < get_movies_number(); i++) {
        int match = 0;
        for (int j = 0; j < i && ! match; j++) {
            if (statistics[i].year == statistics[j].year) {
                match++;
            }
        }
        if (match == 0) {
            diff_years++;
        }
    }
    return diff_years;
}

yearly_income_t* get_yearly_stat(film_t* statistics)
{
    int number_of_years = get_unique_year(statistics);
    yearly_income_t* yearly_stat = calloc(number_of_years, sizeof(yearly_income_t));
    int years = 0;

    for (int i = 0; i < get_movies_number(); ++i) {
        int found = 0;
        for (int j = 0; j < years && !found; ++j) {
            if (statistics[i].year == yearly_stat[j].year) {
                yearly_stat[j].income += statistics[i].income;
                found++;
            }
        }

        if (!found) {
            yearly_stat[years].year = statistics[i].year;
            yearly_stat[years].income = statistics[i].income;
            years++;
        }
    }

    return yearly_stat;
}

int get_best_year(yearly_income_t* yearly_statistics, int years)
{
    long long max_income = 0;
    int best_year = 0;

    for (int i = 0; i < years; ++i) {
        if (max_income < yearly_statistics[i].income) {
            max_income = yearly_statistics[i].income;
            best_year = yearly_statistics[i].year;
        }
    }

    return best_year;
}