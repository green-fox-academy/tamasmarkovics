#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::string;

int main()
{
    std::vector<string> copyBackwards;
    string temp;
    try {
        std::string path = "../reverse.txt";
        std::ifstream inputFile;
        inputFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        inputFile.open(path);

        while(!inputFile.eof()) {
            getline(inputFile, temp);
            copyBackwards.push_back(temp);
        }
        inputFile.close();
    } catch (std::ofstream::failure& traitor) {
        std::cout << traitor.what() << std::endl;
    }

    for (int i = 0; i < copyBackwards.size(); i++){
        std::cout << copyBackwards[copyBackwards.size()-1-i] << std::endl;
    }

    return 0;
}
