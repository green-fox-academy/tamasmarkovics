#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct totally_a_map { //I MISS MAAAAAAPS :'(((((
    char first[200][100];
    int second[200];
    int words;
} totally_a_map_t;

int better_strcmp(char* first, char* second);

int main()
{
    totally_a_map_t word_map;
    word_map.words = 0;
    char* file_loc = "../text.txt";

    FILE *fptr;
    if(!(fptr = fopen(file_loc, "r"))) return -1;

    char line[300];
    //reads in a line
    while (fgets (line , 100 , fptr)) {
        //gets the words
        for (char *word = strtok(line, " ,.:!?'-;\"\n"); word != NULL; word = strtok(NULL, " ,.:!?'-;\"\n")) {
            //fake boolean
            int found = 0;
            //goes thru my totally_a_map and looks for match
            for (int i = 0; i < word_map.words && !found; i++) {
                //better_strcmp doesnt care about case
                if (better_strcmp(word, word_map.first[i])) {
                    //if it matches count goes up, 'found' breaks the loop
                    word_map.second[i]++;
                    found++;
                    //if the word has a lowercase version it overrides the upper
                    if (strcmp(word, word_map.first[i]) > 0) word_map.first[i][0] = word[0];
                }
            }
            //if it 'p' wasn't found, it gets copied into the map, word count goes to 1, so its not something random, number of words goes up
            if (found == 0) {
                strcpy(word_map.first[word_map.words], word);
                word_map.second[word_map.words] = 1;
                word_map.words++;
            }
        }
    }
    fclose(fptr);

    int max = 0; //max number of occurrences
    int max_index = 0; //index of the most common word
    int word_count = 0; //no of individual words
    //all three gets determined
    for (int i = 0; i < word_map.words; i++) {
        if (word_map.second[i] > max) {
            max = word_map.second[i];
            max_index = i;
        }
        word_count += word_map.second[i];
    }

    printf("%d words counted\n", word_count);
    printf("The most common word out of %d different is \"%s\", with an occurrence of %d.\n", word_map.words, word_map.first[max_index], max);
    for (int i = 0; i < word_map.words; i++) {
        printf("%s\t%d\n", word_map.first[i], word_map.second[i]);
    }

    return 0;
}

int better_strcmp(char* first, char* second)
{
    if (strlen(first) != strlen(second)) return 0;
    int i = 0;
    while (first[i] != '\0') {
        if (first[i] == second[i]) {}
        else if (((first[i] > 96 && first[i] < 123) || (second[i] > 96 && second[i] < 123))
                                && ((abs((int)first[i] - (int)second[i]) != 32))) return 0;
        i++;
    }
    return 1;
}