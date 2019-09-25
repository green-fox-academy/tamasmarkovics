#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using std::string;

std::vector<string> getIPs(string filePath);
double getRatio(string filePath);

int main()
{
    std::vector<string> endIp;
    double endRatio = 0;
    // Read all data from 'log.txt'.
    // Each line represents a log message from a web server
    // Write a function that returns an array with the unique IP adresses.
    // Write a function that returns the GET / POST request ratio.
    try {
        std::string path = "../log.txt";
        endIp = getIPs(path);
        endRatio = getRatio(path);
    } catch (std::ofstream::failure& traitor) {
        std::cout << traitor.what() << std::endl;
    }

    std::cout << "Unique IP addresses:" << std::endl;
    for (int i = 0; i < endIp.size(); i++){
        std::cout << endIp[i] << std::endl;
    }
    std::cout << std::endl << "GET/POST ratio is: " << endRatio << std::endl;
    std::cout << "Number of IPs: " << endIp.size();
    return 0;
}


std::vector<string> getIPs(string filePath)
{
    std::ifstream inputFile;
    inputFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    inputFile.open(filePath);

    std::vector<string> logs;

    while(!inputFile.eof()) {
        bool unique = true;
        string temp;
        string tempi;
        getline(inputFile, temp);

        tempi = temp.substr(27, 11);

        for (int i = 0; i < logs.size() && unique; i++) {
            if (logs[i] == tempi){
                unique = false;
            } else unique = true;
        }
        if (unique) {
            logs.push_back(tempi);
        }
    }
    std::sort (logs.begin(), logs.end());
    inputFile.close();


    return logs;
}

double getRatio(string filePath)
{
    std::ifstream inputFile;
    inputFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    inputFile.open(filePath);

    int Get = 0;
    int Post = 0;
    string temp;

    while (!inputFile.eof()) {
        getline(inputFile, temp);

        if (temp.size() == 47) {
            Post++;
        } else if (temp.size() == 46) {
            Get++;
        }
    }
    inputFile.close();
    return (double)Get / Post;
}
