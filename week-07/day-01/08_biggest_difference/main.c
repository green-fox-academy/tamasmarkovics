#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//THIS SOUNDS LIKE FUNDAMENTALLY WRONG? BUT WHERE

typedef struct my_class {
    char* name;
    int students;
    int* marks;
} class_t;

class_t* fill_struct(int size);
void free_struct(class_t* class_to_free, int number_of_classes);

int get_best(class_t* best_in, int class_number);



int main()
{
    printf("How many classes are there?\n");
    int number_of_classes = 0;
    scanf("%d", &number_of_classes);
    class_t* classes = fill_struct(number_of_classes);
    int has_the_best = get_best(classes, number_of_classes);
    printf("%d", has_the_best);
    free_struct(classes, number_of_classes);
    return 0;
}


void free_struct(class_t* class_to_free, int number_of_classes)
{
    for (int i = 0; i < number_of_classes; ++i) {
        free(class_to_free[i].name);
        free(class_to_free[i].marks);
    }
    free(class_to_free);
}

class_t* fill_struct(int size)
{
    class_t* school = malloc(size * sizeof(class_t));
    for (int i = 0; i < size; ++i) {
        //GET NAME
        printf("Name?\n");
        char* temp = malloc(sizeof(char) * 100);
        scanf("%s", temp);
        temp = realloc(temp, strlen(temp) + 1);
        school[i].name = temp;

        //NUMBER OF STUDENTS
        printf("No of students?\n");
        int size_of_students = 0;
        scanf("%d", &size_of_students);
        school[i].students = size_of_students;

        //RESULTS
        int *results = malloc(size_of_students * sizeof(int));
        printf("Results of students?\n");
        for (int j = 0; j < size_of_students; ++j) {
            scanf("%d", results + j);
        }
    }

    return school;
}
