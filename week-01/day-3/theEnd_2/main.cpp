#include <iostream>

int main() {

    //diamond
    int dia = 0;
    std::cout << "Give a number for my diamond" << std::endl;
    std::cin >> dia;

    for (int d = 0; d <= dia / 2; d++){
        for (int d1 = dia / 2 - d; d1 >= 0; d1--){
            std::cout << " ";
        }
        for (int d2 = 1; d2 < 2 * d; d2++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    if (dia % 2 != 0){
        for (int kozep = 0; kozep<dia; kozep++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    for (int d = dia / 2; d > 0; d--){
        for (int d1 = dia / 2 - d; d1 >= 0; d1--){
            std::cout << " ";
        }
        for (int d2 = 1; d2 < 2 * d; d2++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    //square
    int sqr = 1;
    std::cout << "Give a number for my square" << std::endl;
    std::cin >> sqr;

    for (int a = 1; a <= sqr; a++){
        if (a == 1 || a == sqr){
            for (int b = 1; b <= sqr; b++) {
                std::cout << "%";
            }
            std::cout << std::endl;
        } else {
            std::cout << "%";
            for (int c = 1; c <= sqr - 2; c++) {
                std::cout << " ";
            }
            std::cout << "%" << std::endl;
        }
    }

    //Diagonal
    int diag = 1;
    std::cout << "Give a number for my other square" << std::endl;
    std::cin >> diag;

    for (int sor = 1; sor <= diag; sor++){
        if (sor == 1 || sor == diag){
            for (int b = 1; b <= diag; b++) {
                std::cout << "%";
            }
            std::cout << std::endl;
        } else {
            std::cout << "%";
            for (int oszlop = 2; oszlop <= diag - 1; oszlop++) {
                if (sor == oszlop){
                    std::cout << "%";
                } else std::cout << " ";
            }
            std::cout<< "%" << std::endl;
        }
    }

    //tippmix
    int tipp = 0;
    int theOne = 22;
    while (tipp != theOne){
        std::cout << "Give me a tip!" << std::endl;
        std::cin >> tipp;
        if (tipp != theOne){
            if (tipp > theOne){
                std::cout << "Too big" << std::endl;
            } else
                std::cout << "Too small" << std::endl;
        } else std::cout << "Nice Job!" << std::endl;
    }





    return 0;
}