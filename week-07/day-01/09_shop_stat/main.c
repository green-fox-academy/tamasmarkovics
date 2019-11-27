#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////How many customers the shop had that day? - DONE
////What was the time with the most traffic?(Sum of incoimng and outgoing customers) - DONE
////When the shop needs the most cashiers?(When was the time the most customer was in the store)
////Does it worth to keep the shop open in the last 2 hours? It's worth it if at least 5% of the total customers was in the store at the last 2 hours.

typedef struct hourly {
    char timezone[12];
    char* stats;
} hour_t;

int get_size();
hour_t* fill_struct();
int get_customers(hour_t* stat_struct, int size);
char* most_frequented_hour(hour_t* stat_struct, int size);

int main() {

    hour_t* opening_stats = fill_struct();
    int hrs = get_size();

    printf("%d has visited the shop\n", get_customers(opening_stats, hrs));
    printf("Biggest traffic in %s\n", most_frequented_hour(opening_stats, hrs));
    //printf("Visits in last 2 hrs is %d\n", in_last_two);
    for (int e = 0; e < hrs; e++) {
        free(opening_stats[e].stats);
    }
    free(opening_stats);
    return 0;
}

int get_size()
{
    FILE *fptr;
    if (!(fptr = fopen("../stats.txt", "r"))) return -1;
    char openhrs[5];
    fscanf(fptr,"%s\n", openhrs);
    fclose(fptr);
    return atoi(openhrs);
}
hour_t* fill_struct() {
    FILE *fptr;
    if (!(fptr = fopen("../stats.txt", "r"))) return NULL;

    char openhrs[5];
    fscanf(fptr, "%s\n", openhrs);
    int hrs = atoi(openhrs);

    hour_t *opening_stats = calloc(hrs, sizeof(hour_t));

    char timezone[12];
    char tmp[200];
    int i = 0;
    while (fscanf(fptr, " %s %[^\n] ", timezone, tmp) == 2 && i < hrs) {
        memcpy(opening_stats[i].timezone, timezone, 12);
        opening_stats[i].stats = calloc(strlen(tmp) + 1, sizeof(char));
        memcpy(opening_stats[i].stats, tmp, strlen(tmp) + 1);
        i++;
    }
    fclose(fptr);
    return opening_stats;
}
int get_customers(hour_t* stat_struct, int size)
{
    int visits = 0;
    char* temp = malloc(1);
    for (int i = 0; i < size; i++) {
        temp = realloc(temp, (strlen(stat_struct[i].stats) + 1) * sizeof(char));
        memcpy(temp, stat_struct[i].stats, strlen(stat_struct[i].stats) + 1);
        for (char *p = strtok(temp, " "); p != NULL; p = strtok(NULL, " ")) {
            visits += atoi(p);
        }
    }
    free(temp);
    return visits;
}

char* most_frequented_hour(hour_t* stat_struct, int size)
{
    int max = 0;
    char* best_hr;
    char* temp = malloc(1);

    for (int i = 0; i < size; i++) {
        int visits_per_hr = 0;
        temp = realloc(temp, (strlen(stat_struct[i].stats) + 1) * sizeof(char));
        memcpy(temp, stat_struct[i].stats, strlen(stat_struct[i].stats) + 1);

        for (char *p = strtok(temp, " "); p != NULL; p = strtok(NULL, " ")) {
            visits_per_hr++;
        }

        if (max < visits_per_hr) {
            max = visits_per_hr;
            best_hr = stat_struct[i].timezone;
        }
    }
    free(temp);
    return best_hr;
}