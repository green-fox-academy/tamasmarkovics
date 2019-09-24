#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream miFile;
    miFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    // Open a file called "my-file.txt"
    // Write your name in it as a single line

    try{
        miFile.open("my-file.txt");
        miFile << "your name in it as a single line";
        miFile.close();
    } catch (std::ofstream::failure& e) {
        std::cout << e.what() << std::endl;
    }


    return 0;
}