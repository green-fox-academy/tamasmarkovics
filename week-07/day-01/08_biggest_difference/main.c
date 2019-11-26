#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct classess {
    char* name;
    int students;
    int* marks;
} class_t;

class_t* fill_struct(int size);
void free_struct(class_t* class_to_free, int number_of_classes);
int get_best(class_t* best_in, int class_number);
void printstruct(class_t* to_print, int number_of_classes);
float get_all_average(class_t* to_print, int number_of_classes);
void biggest_diff(class_t* to_print, int number_of_classes);

int main()
{
    printf("How many classes are there?\n");
    int number_of_classes = 0;
    scanf("%d", &number_of_classes);
    class_t* classes = fill_struct(number_of_classes);
    int has_the_best = 0;
    has_the_best = get_best(classes, number_of_classes);
    printf("The best result is in class %s\n", classes[has_the_best].name);
    float average = get_all_average(classes, number_of_classes);
    printf("The whole average is %f\n", average);
    biggest_diff(classes, number_of_classes);
    //printstruct(classes, number_of_classes);
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

        char* temp = malloc(sizeof(char) * 20);
        scanf(" %[^\n]s", temp);
        school[i].name = calloc(sizeof(char), strlen(temp) + 1);
        memcpy(school[i].name, temp, strlen(temp));
        free(temp);

        printf("%s\n", school[i].name);

        //NUMBER OF STUDENTS
        printf("No of students?\n");
        int size_of_students = 0;
        scanf("%d", &size_of_students);
        school[i].students = size_of_students;

        //RESULTS
        school[i].marks = malloc(size_of_students * sizeof(int));
        printf("Results of students?\n");
        for (int j = 0; j < size_of_students; ++j) {
            scanf("%d", &school[i].marks[j]);
        }
    }
    return school;
}



int get_best(class_t* best_in, int class_number)
{
    int max = 0;
    int index = 0;
    for (int i = 0; i < class_number; i++) {
        for (int j = 0; j < best_in[i].students; j++) {
            if (max < best_in[i].marks[j]) {
                max = best_in[i].marks[j];
                index = i;
            }
        }
    }
    return index;
}


void printstruct(class_t* to_print, int number_of_classes)
{
    for (int i = 0; i < number_of_classes; i++) {
        printf("%s class has %d students, with reults:\n", to_print[i].name, to_print[i].students);
        for (int j = 0; j < to_print[i].students; j++) {
            printf("%d\n", to_print[i].marks[j]);
        }
    }
}


float get_all_average(class_t* to_print, int number_of_classes)
{
    int sum = 0;
    int students = 0;
    for (int i = 0; i < number_of_classes; i++) {
        students += to_print[i].students;
        for (int j = 0; j < to_print[i].students; j++) {
            sum += to_print[i].marks[j];
        }
    }
    return sum / (float)students;
}


void biggest_diff(class_t* to_print, int number_of_classes)
{
    int difff = 0;
    int index = 0;
    for (int i = 0; i < number_of_classes; i++) {
        int min = to_print[i].marks[0];
        int max = to_print[i].marks[0];
        for (int j = 1; j < to_print[i].students; j++) {
            min = min > to_print[i].marks[j] ? to_print[i].marks[j] : min;
            max = max < to_print[i].marks[j] ? to_print[i].marks[j] : max;
        }
        if ( difff < max - min) {
            difff = max - min;
            index = i;
        }
    }
    printf("\n%s class has the biggest difference, with %d\n", to_print[index].name, difff);
}