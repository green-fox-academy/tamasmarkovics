#include <iostream>
#include <string>
using namespace std;

void searchPali(string search);



//RUNS 4EVER WATCH OUT!
//hot mess RN
//acces violation error, INDEXING PROBLEM???!!!???



int main() {
    //Create a function named search palindrome following your current language's style guide. It should take a string,
    //search for palindromes that at least 3 characters long and return a list with the found palindromes.

    string toSearch = "dasd dsafads fadscs adasdasdasda adda cddccsdwedw sacs xsa adsda adsas asdas asdda asdasdsa";

    searchPali(toSearch);
    return 0;
}

void searchPali(string search){
    int size = search.length();
    string listOfPalis[size];
    int count = 0;//No. of palis. Bad name, should change

    //checks every char
    for(int j = 1; j < size-1; ++j) {


        //inside, so it starts with true every cycle, and doesnt stop fors
        bool paliQuestionmark = true;

        //compares the next one --->> finding ABBA
        if (search[j] == search[j+1]){

            //supposed to stop if they arent the same, work in progresss...............
            for (int i = 0; (i < 2 * j) && paliQuestionmark == true; ++i) {


                if (search[j-i]==search[j+1+i]){
                    paliQuestionmark = true;
                    listOfPalis[count] = search.substr(j-1-i, (2*i+2));  //example showed every subPali of a longer Pali written out too, sound easier, but whatever
                    count++;
                } else{
                    paliQuestionmark = false;
                };




            }
        }
        //this is supposed to find the odd length palis ---->> finding ABA
        else {


            for (int k = 0; (k < 2 * j) && paliQuestionmark == true; ++k) {
                if (search[j - k] == search[j + k]) {
                    paliQuestionmark = true;
                    listOfPalis[count] = search.substr(j - k, (2 * k + 1));
                    count++;
                } else {
                    paliQuestionmark = false;



                };
            }
        };
    }
    for (int l = 0; l < count; ++l) {
        cout << listOfPalis[l] << endl;
    }
}

