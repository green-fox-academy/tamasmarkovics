#include <iostream>
#include <sstream>
#include <fstream>

int main() {

    // Create a program that decrypts the file called "duplicated-chars.txt",
    // and pritns the decrypred text to the terminal window.

    std::ifstream inputFile ("../double.txt");
    std::string row;
    while (std::getline(inputFile, row)) {
        for (int i = 0; i < row.size(); i++){
            row.erase(i, 1);
        }
        std::cout << row << std::endl;
    }

    return 0;
}