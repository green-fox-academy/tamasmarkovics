#include <iostream>
#include <exception>
#include <fstream>
#include <string>


int main() {
    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file first.


    std::ifstream myFile;
    myFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        myFile.open("text.txt");
        std::string text;
        int lines = 0;
        while(!myFile.eof()) {
            getline(myFile, text);
            std::cout << text << std::endl;
            lines++;
        }
        // Write a function that takes a filename as string,
        // then returns the number of lines the file contains.
        // It should return zero if it can't open the file.
        std::cout << lines << std::endl;

        myFile.close();
    } catch (std::ifstream::failure& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}