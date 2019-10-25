#include <stdio.h>
#include <string.h>


typedef struct totally_a_map { //I MISS MAAAAAAPS :'(((((
    char first[200][100];
    int second[200];
    int words;
} totally_a_map_t;



int main()
{
    FILE *fptr;
    char* file_loc = "../text.txt";

    totally_a_map_t word_map;
    if(!(fptr = fopen(file_loc, "r"))) return -1;
    char line[300];
    word_map.words = 0;


    while (fgets (line , 300 , fptr)) {
        for (char *p = strtok(line, " ,.:!?'-;\"\n"); p != NULL; p = strtok(NULL, " ,.:!?'-;\"\n")) {
            int found = 0;
            for (int i = 0; i < word_map.words && !found; i++) {
                if (!strcmp(p, word_map.first[i])) {
                    word_map.second[i]++;
                    found++;
                }
            }
            if (found == 0) {
                strcpy(word_map.first[word_map.words], p);
                word_map.second[word_map.words] = 1;
                word_map.words++;
            }
        }
    }
    fclose(fptr);

    int max = 0;
    int max_index = 0;
    for (int i = 0; i < word_map.words; i++) {
        if (word_map.second[i] > max) {
            max = word_map.second[i];
            max_index = i;
        }
    }

    printf("The most common word out of %d is \"%s\", with an occurance of %d.\n", word_map.words, word_map.first[max_index], max);
    for (int i = 0; i < word_map.words; i++) {
        printf("%s\t%d\n", word_map.first[i], word_map.second[i]);
    }


    return 0;
}