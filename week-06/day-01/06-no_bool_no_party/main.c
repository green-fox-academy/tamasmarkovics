#include <stdio.h>

int is_old_enough(int age);
int are_they_equal(int one, int two);
int is_even(int number);

int main() {

    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary
    printf("Wie alt bis du?\n");
    int age;
    scanf("%d", &age);
    printf("%d", is_old_enough(age));


    // Create a program which asks for two integers and stores them separatly
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise
    printf("\nGive me two numbers!\n");
    int num1, num2;
    scanf("%d%d", &num1, &num2);
    if (are_they_equal(num1, num2)) {
        printf("%d and %d are equal! Me smart\n", num1, num2);
    } else printf("%d and %d aren't equal! Me smart\n", num1, num2);


    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter and
    // returns 1 if that number is even and returns 0 otherwise
    // (in this case 0 is an even number)
    if (is_even(num1)) {
        printf("%d is even! Me smart\n", num1);
    } else printf("%d is not even! Me soooo smart\n", num1);

    return 0;
}

int is_old_enough(int age)
{
    if (age < 18) {
        return 0;
    } else return 1;
}

int are_they_equal(int one, int two)
{
    if (one == two) {
        return 1;
    } else return 0;
}

int is_even(int number)
{
    if (number % 2 == 0) {
        return 1;
    } return 0;
}