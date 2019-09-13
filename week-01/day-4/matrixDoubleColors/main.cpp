#include <iostream>


int main() {
    // - Create (dynamically) a two dimensional array
    //   with the following matrix. Use a loop!
    //   by dynamically, we mean here that you can change the size of the matrix
    //   by changing an input value or a parameter or this combined
    //
    //   1 0 0 0
    //   0 1 0 0
    //   0 0 1 0
    //   0 0 0 1
    //
    // - Print this two dimensional array to the output
    int N = 1;
    std::cout << "how big?" << std::endl;
    std::cin >> N;
    int matrix[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                matrix[i][j]= 1 ;
            }else matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }


    // - Create an array variable named `numList`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Double all the values in the array
    int numList[] = {3, 4, 5, 6, 7};
    for (int k = 0; k < 5; ++k) {
        std::cout << numList[k] << " -> ";
        numList[k] *=2;
        std::cout << numList[k] << std::endl;
    }

    // - Create a two dimensional array
    //   which can contain the different shades of specified colors
    // - In `colors[0]` store the shades of green:
    //   `"lime", "forest green", "olive", "pale green", "spring green"`
    // - In `colors[1]` store the shades of red:
    //   `"orange red", "red", "tomato"`
    // - In `colors[2]` store the shades of pink:
    //   `"orchid", "violet", "pink", "hot pink"`
    std::string colors[3][6] = {"green", "lime", "forest green", "olive", "pale green", "spring green", "red", "orange red", "red", "tomato", "%", "%", "pink", "orchid", "violet", "pink", "hot pink", "%"};
    for (int l = 0; l < 3; ++l) {
        std:: cout << colors[l][0] << ": ";
        for (int i = 1; i < 6 && colors[l][i] != "%" ; ++i) {
            std::cout << colors[l][i] << ", ";
        }
        std::cout << std::endl;
    }




    return 0;
}