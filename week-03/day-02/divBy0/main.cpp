#include <iostream>

int main() {
    //WITHOUT EXCEPTIONS
    int con = 10;
    int inp;
    std::cin >> inp;
    if (inp == 0) {
        std::cout << "FAIIIL" << std::endl;
    } else {
        std::cout << con / inp << std::endl;
    }

    //WITH EXCEPTIONS
    try {
        int a = 10;
        int b;
        std::cin >> b;
        if (b == 0) {
            throw std::string("FAIIIL");
        }
        std::cout << a / b << std::endl;
    } catch (std::string& e) {
        std::cout << e << std::endl;
    }

    return 0;
}