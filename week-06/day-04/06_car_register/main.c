
#include <string.h>
#include <stdio.h>

/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int array_length, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */

enum transmission {
    MANUAL,
    AUTO,
    CVT,
    SEMI_AUTOMATIC,
    DUAL_CLUTCH
};

struct car {
    char name[256];
    float price;
    int production_year;
    enum transmission trans;
};

int get_older_cars_than(struct car* array, int array_length, int age)
{
    int count_old = 0;
    for (int i = 0; i < array_length; ++i) {
        count_old += array[i].production_year < (2019 - age);
    }
    return count_old;
}

int get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
{
    int count_trnsm = 0;
    for (int i = 0; i < array_length; ++i) {
        count_trnsm += array[i].trans == trnsm;
    }
    return count_trnsm;
}


int main()
{
    struct car a = {"a", 2432.23f, 2018, AUTO};
    struct car b = {"b", 432234.334f, 2014, SEMI_AUTOMATIC};
    struct car c = {"b", 94.334f, 2014, DUAL_CLUTCH};
    struct car d = {"b", 6454.334f, 1988, MANUAL};
    struct car e = {"b", 47234.334f, 1995, MANUAL};
    struct car f = {"b", 4324.334f, 2000, MANUAL};
    struct car g = {"b", 434.334f, 2004, SEMI_AUTOMATIC};

    struct car cars[] = {a, b, c, d, e, f, g};

    int age = 14;
    printf("%d cars older than %d\n", get_older_cars_than(cars, 7, age), age);
    printf("%d cars have auto transmission\n", get_transmission_count(cars, 7, AUTO));
    printf("%d cars have manual transmission\n", get_transmission_count(cars, 7, MANUAL));

    return 0;
}