#include <iostream>
#include <fstream>
#include <string>
// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

void miWritingFunc(std::string path, std::string word, int repetition);

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

void miCopyFunc(std::string path);

int main() {
    try{
        std::string path = "text.txt";
    //miWritingFunc(path, "one more line!", 5);
    miCopyFunc(path);
    } catch (std::ofstream::failure& traitor) {
        std::cout << traitor.what() << std::endl;
    }

    return 0;
}


void miWritingFunc(std::string path, std::string word, int repetition){
    std::ofstream outputFile;
    outputFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    outputFile.open(path);
    for (int i = 0; i < repetition; i++) {
        outputFile << word << "\n";
    }
    outputFile.close();
}


void miCopyFunc(std::string path){
    std::ifstream inputFile;
    std::ofstream outputFile;
    outputFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);

    inputFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    inputFile.open(path);
    outputFile.open("iCopyHere.txt");

    std::string temp;
    bool wasItOk = false;
    getline(inputFile, temp);
    outputFile << temp;
    while(!inputFile.eof()) {
        outputFile << "\n";

        getline(inputFile, temp);
        outputFile << temp;
        wasItOk = true;
    }
    std::cout << wasItOk << std::endl;

    outputFile.close();
    inputFile.close();
}