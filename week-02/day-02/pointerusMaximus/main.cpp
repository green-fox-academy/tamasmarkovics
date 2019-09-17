#include <iostream>

int main() {

    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it

    std::cout << "Give me a number!" << std::endl;
    int num = 1;
    std::cin >> num;
    std::cout << "Now give me " << num << " numbers!" << std::endl;
    int arr[num];
    for (int i = 0; i < num; ++i) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < num; ++i) {
        std::cout << arr[i] << std::endl;
    }
    int max = 0;
    for (int j = 0; j < 5; ++j) {
        if (max < arr[j]) {
            max = arr[j];
        }
    }

    std::cout << &max << " --> " << max << std::endl;

    return 0;
}

