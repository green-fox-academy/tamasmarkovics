#ifndef MYAPP_APPLES_H
#define MYAPP_APPLES_H

#include <string>
#include <vector>
using std::vector;
using std::string;

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


bool anagram(string input1, string input2){
    bool sofar;
    if (input1.length() == input2.length()){
        sofar = true;
        for (int i = 0; ((i < input1.length()) && sofar); ++i) {
            sofar = input1[i] == input2[input2.length() - 1 - i];;
        }
    } else sofar = false;

    return sofar;
}



#endif //MYAPP_APPLES_H
