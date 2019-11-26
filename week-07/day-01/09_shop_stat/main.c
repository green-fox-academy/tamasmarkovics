#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* fptr;
    if (!(fptr = fopen("stats.txt", "r"))) return -1;

    int i = 0;
    char timezone[12];
    char tmp[100];
    int visits = 0;
    int count = 0;
    while (fscanf(fptr, "%11[] %s\n", timezone, tmp) == 2) {
        for (char *p = strtok(tmp, " "); p != NULL; p = strtok(NULL, " ")) {
            count++;
            visits += atoi(p);
        }
        i++;
    }

    fclose(fptr);
    return 0;
}