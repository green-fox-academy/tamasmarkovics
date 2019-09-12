#include <iostream>

int main() {
    // Write a program that asks for a number.
    // It would ask this many times to enter an integer,
    // if all the integers are entered, it should print the sum and average of these
    // integers like:
    //
    // Sum: 22, Average: 4.4
    int num = 0;
    int temp = 0;
    int sum = 0;
    std::cout << "How many?" << std::endl;
    std::cin >> num;
    std::cout << "Give me " << num << " numbers!" << std::endl;
    for (int count = 1; count <= num; count++){
        std::cin >> temp;
        sum += temp;
        if (count != num){
            std::cout << "MORE!!" << std::endl;
        } else
            std::cout << "Sum:" << sum << " Average: " << (double)sum / num << std::endl;
    }
    return 0;
}