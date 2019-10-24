#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct car {
    enum car_type type;
    double km;
    double gas;
};

void print_car_stats(struct car my_car)
{
    switch (my_car.type) {
        case VOLVO : printf("A Volvo car, that has %.2lf kms, and %.2lf gas.\n", my_car.km, my_car.gas); break;
        case TOYOTA : printf("A Toyota car, that has %.2lf kms, and %.2lf gas.\n", my_car.km, my_car.gas); break;
        case LAND_ROVER : printf("A Land Rover car, that has %.2lf kms, and %.2lf gas.\n", my_car.km, my_car.gas); break;
        case TESLA : printf("A Tesla car, that has %.2lf kms, and no gas.\n", my_car.km); break;
        default: printf("no such car\n");
    }
}

int main()
{
    struct car xc90 = {VOLVO, 324.54, 66.54};
    print_car_stats(xc90);
    return 0;
}