#include "extension.h"

#include <algorithm>
#include <sstream>
#include <string>
using std::string;

int add(int a, int b)
{
    return a + b;
}

int maxOfThree(int a, int b, int c)
{
    if (a > b){
        if(a > c) {
            return a;
        } else return c;
    } else if (b > c){
        return b;
    } else return c;
}

int median(const std::vector<int>& pool) {
    return pool.at((pool.size()-1)/2);
}

bool isVowel(char c) {
    static const std::vector<char> vowels = {'a', 'u', 'o', 'e', 'i'};
    return std::find(vowels.begin(), vowels.end(), c) != vowels.end();
}

std::string translate(const std::string& hungarian)
{
    std::string teve = hungarian;
    int length = teve.size();
    for (int i = 0; i < length; i++) {
        const char c = teve.at(i);
        if (isVowel(c)) {
            std::string toinsert = "v";
            toinsert.push_back(c);
            teve = teve.insert(i + 1, toinsert);
            i+=2;
            length+=2;
        }
    }
    return teve;
}

// Check out the folder. There's a work file and a test file.

//  -  Run the tests, all 10 should be green (passing).
//  -  The implementations though are not quite good.
//  -  Create tests that'll fail, and will show how the implementations are wrong(You can assume that the implementation of join and split are good)
//  -  After creating the tests, fix the implementations
//  -  Check again, if you can create failing tests
//  -  Implement if needed