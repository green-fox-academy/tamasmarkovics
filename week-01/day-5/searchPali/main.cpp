#include <iostream>
#include <string>
using namespace std;

void searchPali(string search);

int main() {
    //Create a function named search palindrome following your current language's style guide. It should take a string,
    //search for palindromes that at least 3 characters long and return a list with the found palindromes.

    string toSearch = "dasd dsafads fadscs adasdasdasda csdwedw sacs xsa adsda adsas asdas asdda asdasdsa";

    searchPali(toSearch);
    return 0;
}

void searchPali(string search){
    /*
     <<<<thinking>>>
    beginning has to be the end too -> can just search for it?...
                                              what if the next one is? -> change to double digit search?
    consider it done... if a match is found check for pali
    if it fails i can go on to the next match
                      -> can only work if the first match is halfway, i can skip there! or can i? wink wink
    other shortcuts?
        START WITH 2 CHARS
            -> works with finding 3 long palis
                    -> BACKWARDS!!!!
        skip starting with spaces, maybe check it after

    a long pali will have A LOOOOT of subPalis, how do i deal with that? what are the odds i guess?

    OOOOOR
    possibly matching longer lines every time? sounds like more runtime
    */
    int size = search.length();
    int found = 0;
    // FOR to go thru the string
    string temp = search.substr(2,2);
    swap(temp[0], temp[1]);
    //for? while? to find every single instance *** possible shortcut with skipping searches.
    found=search.find(temp, 2);
    cout << temp << " found at: " << found << '\n';
}

