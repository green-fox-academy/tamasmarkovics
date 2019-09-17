#include <iostream>

int main() {

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    int *aPtr = &a;
    double *bPtr = &b;
    std::string *namePtr = &name;

    std::cout << *aPtr << std::endl << *bPtr << std::endl << *namePtr << std::endl;
    std::cout << aPtr << std::endl << bPtr << std::endl << namePtr << std::endl;

    int age = 31;
    int *agePtr = &age;
    std::cout << *agePtr << std::endl;


    float temperature = 21.3;
    float *tempPtr = &temperature;
    *tempPtr = 63;
    std::cout << *tempPtr << std::endl;

    double sum = *aPtr + *bPtr;
    std::cout << sum << std::endl;


    return 0;
}