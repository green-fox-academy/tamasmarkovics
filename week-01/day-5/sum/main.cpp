#include <iostream>

int sum(int until);
int main() {
    // Write a function called `sum` that returns the sum of numbers from zero to the given parameter

    std::cout << sum(6) << std::endl;

    return 0;
}


int sum(int until){
    int sum = 0;
    for (int i = 1; i < until ; ++i) {
        sum += i;
    }
    return sum;
}