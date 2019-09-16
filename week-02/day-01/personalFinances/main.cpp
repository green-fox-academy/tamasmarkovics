#include <iostream>
#include <vector>

//Personal finance
//We are going to represent our expenses in a list containing integers.
//
//Create a list with the following items.
//500, 1000, 1250, 175, 800 and 120
//Create an application which solves the following problems.
//How much did we spend?
//Which was our greatest expense?
//Which was our cheapest spending?
//What was the average amount of our spendings?

int main() {
    std::vector<int> expenses = {500, 1000,1250, 175, 800, 120};
    int sum = 0;
    for (int i = 0; i < expenses.size(); ++i) {
        sum += expenses[i];
    }
    int greatest = 0;
    for (int j = 0; j < expenses.size(); ++j) {
        if (expenses[j] > greatest) {
            greatest = expenses[j];
        }
    };
    int csipeszt = 0;
    for (int k = 0; k < expenses.size(); ++k) {
        if (expenses[k] < csipeszt || k == 0) {
            csipeszt = expenses[k];
        }
    };

    int average = sum/expenses.size();

    std::cout << sum << std::endl << greatest << std::endl << csipeszt << std::endl << average;


    return 0;
}