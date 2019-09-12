#include <iostream>

int main() {
    // Crate a program that draws a chess table like this
    //
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    std::cout << "How big would you like? Height first pls ty :)" << std::endl;
    int wid = 0;
    int hei = 0;
    std::cin >> hei;
    std::cout << "Now width" << std:: endl;
    std::cin >> wid;
    for (int i = 1; i <= hei; i++) {
        if (i % 2 == 0) {
            for (int p=1; p <= wid; p++) {
                if (p % 2 != 0) {
                    std::cout << " ";
                } else
                    std::cout << "%";
            }
        } else {
            for (int p=1; p <= wid; p++) {
                if (p % 2 == 0) {
                    std::cout << " ";
                } else
                    std::cout << "%";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}