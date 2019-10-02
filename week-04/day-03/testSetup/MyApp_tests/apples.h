#ifndef MYAPP_APPLES_H
#define MYAPP_APPLES_H

#include <string>
#include <vector>
#include <map>
using std::vector;
using std::string;
using std::map;
using std::pair;

std::string getApple()
{
    return "apple";
}

int sum(vector<int> toSum)
{
    int sum = 0;
    for(int i = 0; i < toSum.size(); i++){
        sum += toSum[i];
    }
    return sum;
}


bool anagram (std::string inputA, std::string inputB)
{
    bool ifAnagram = false;
    if (inputA.length() == inputB.length()) {
        std::sort(inputA.begin(), inputA.end());
        std::sort(inputB.begin(), inputB.end());
        ifAnagram = inputA == inputB;
    }
    return ifAnagram;
}

map<char, int> countLetters(string toBeCounted)
{
    map<char, int> letters;
    for(unsigned int i = 0; i < toBeCounted.length(); i++){
        if (letters.count(toBeCounted[i]) == 0){
            pair<char, int> newLetter(toBeCounted[i], 1);
            letters.insert(newLetter);
        } else letters[toBeCounted[i]]++;
    }

    return letters;
}




#endif //MYAPP_APPLES_H
