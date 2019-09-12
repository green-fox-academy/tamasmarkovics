#include <iostream>

int main() {

    std::cout << "How big would you like? Height first pls ty :)" << std::endl;
    int wid = 1;
    int hei = 1;
    std::cin >> hei;
    std::cout << "Now width" << std:: endl;
    std::cin >> wid;
    for (int i = 1; i <= hei; i++) {
        int w;
        if (i % 2 == 0) {
            w = wid - 1;
            std::cout << "_";
        } else w = wid;
        for (int p = 1; p <= w; p++) {
            if (p % 2 == 0) {
                std::cout << "_";
            } else std::cout << "%";
        }
        std::cout << std::endl;
    }
    return 0;
}