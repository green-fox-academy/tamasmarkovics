#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

int main() {

    // Create a program that decrypts the file called "reversed-lines.txt",
    // and pritns the decrypred text to the terminal window.

    std::ifstream inputFile ("../reverse.txt");
    std::string row;
    char temp;
    while (std::getline(inputFile, row)) {
        getline(inputFile, row);
        for (int i = 0; i < row.size()/2; i++){
            temp = row[i];
            row[i] = row[row.size()-1-i];
            row[row.size()-1-i] = temp;

        }
        std::cout << row << std::endl;
    }

    return 0;
}