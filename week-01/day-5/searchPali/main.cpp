#include <iostream>
#include <string>
using namespace std;
void searchPali(string search);

int main() {
    string toSearch = "sdsadas sdasdas asas saaas sdads";
    searchPali(toSearch);
    return 0;
}

void searchPali(string search){
    int size = search.length();
    string listOfPalis[size];                                                               //size should be enough.. hopefully
    int paliNum = 0;                                                                        //No. of palis.
    for(int j = 1; j < size - 1; ++j) {                                                     //checks every char
        bool paliQuestionmark = true;                                                       //inside, so it starts with true every cycle, and doesnt stop fors
        int n;                                                                              //basicly switches between ABA and ABBA
        if (search[j] == search[j + 1]){                                                    //compares the next one --->> finding ABBA
            n = 2;
        } else n = 1;                                                                       //---->> finding ABA
        for (int i = 1; (i < 2 * j) && paliQuestionmark == true; ++i) {                     //paliQuestionmark is supposed to stop if they arent the same
            if (search[j - i] == search[j + n - 1 + i]){                                    //n switches between even and odd long
                paliQuestionmark = true;
                listOfPalis[paliNum] = search.substr(j - i, (2 * i + n));           //the example showed every subPali of a longer Pali written out, so be it...
                paliNum++;
            } else paliQuestionmark = false;
        }
    }
    cout << "Palindromes in \"" << search << "\":" << endl;
    for (int l = 0; l < paliNum; ++l) {
        cout << "\"" <<listOfPalis[l] << "\"" << endl;
    }
}