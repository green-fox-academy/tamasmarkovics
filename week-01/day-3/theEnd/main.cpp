#include <iostream>
#include <string>

int main() {
    /*
    //iWontCheat
    for (int i=0; i<10;i++) {
        std::cout << "I won't cheat on the exam!" << std::endl;
    }
    std::cout << std::endl;
    //printEvent
    for (int i=0; i<=10;i+=2) {
        std::cout << i <<std::endl;
    }
    std::cout << std::endl;
    //Multiplication table
    std::cout << "Pick a number for the multiplication table" << std::endl;
    int multi = 0;
    std::cin >> multi;
    for (int m = 1; m <= 10; m++) {
        std::cout << m << " * " << multi << " = " << m * multi << std::endl;
    }
    // Create a program that asks for two numbers
    // If the second number is not bigger than the first one it should print:
    // "The second number should be bigger"
    //
    // If it is bigger it should count from the first number to the second by one
    //
    // example:
    //
    // first number: 3, second number: 6, should print:
    //
    // 3
    // 4
    // 5
    std::cout << std::endl;
    int smll = 1;
    int bg = 1;
    std::cout << "Pls gimme 2 numbers, make the second one bigger." << std::endl;
    std::cin >> smll >> bg;
    if (smll>bg){
        std::cout << "Learn how to read you moron" << std::endl;
    } else {
        for (smll; smll <= bg; smll++) {
            std::cout << smll << std::endl;
        }
    };
    std::cout << std::endl;

    // Write a program that prints the numbers from 1 to 100.
    // But for multiples of three print “Fizz” instead of the number
    // and for the multiples of five print “Buzz”.
    // For numbers which are multiples of both three and five print “FizzBuzz”.
    for (int f = 1; f < 100; f++ ){
        if (f % 3 == 0 && f % 5 == 0){
            std::cout << "FizzBuzz" << std::endl;
        }else
            if (f % 3 == 0){
                std::cout << "Fizz" << std::endl;
            } else
                if (f % 5 == 0){
                    std::cout << "Buzz" << std::endl;
                } else
                    std::cout << f << std::endl;

    }


    // Write a program that reads a number from the standard input, then draws a
    // triangle like this:
    //
    // *
    // **
    // ***
    // ****
    //
    // The triangle should have as many lines as the number was
    int tri = 0;
    std::cout << "Give a number for my triangle" << std::endl;
    std::cin >> tri;
    for(int t = 1; t<=tri; t++){
        for(int t2 = 1; t2<=t; t2++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    */
    int pyr = 0;
    std::cout << "Give a number for my pyramid" << std::endl;
    std::cin >> pyr;
    for(int p = 0; p<=pyr; p++){
        for(int p1 = pyr-p; p1>=0; p1--){
            std::cout << " ";
        }
        for(int p2 = 0; p2<2*p-1; p2++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }


    return 0;
}