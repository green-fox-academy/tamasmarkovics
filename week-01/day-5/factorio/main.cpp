#include <iostream>
void factorio(int factorialTo, int& count);
int main() {
    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.
    int x;
    factorio(5, x);
    std::cout << x << std::endl;
    return 0;
}
void factorio(int factorialTo, int& count){
    count= 1;
    for (int i = 1; i < factorialTo ; ++i) {
        count *= i;
    }
}
