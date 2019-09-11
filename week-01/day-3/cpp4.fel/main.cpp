#include <iostream>

int main() {

    // Modify this program to greet user instead of the World!
    // The program should ask for the name of the user
    std::string name="";
    std::cout<<"Neved?"<<std::endl;
    std::cin>>name;
    std::cout << "Hello " << name<< std::endl;

    // Write a program that asks for a double that is a distance in miles,
    // then it converts that value to kilometers and prints it
    double miles=0;
    std::cout<<"Wie vielen merfolden? (double pls)"<<std::endl;
    std::cin>>miles;
    std::cout<<miles*0.8<<std::endl;

    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have
    int chick=0;
    int pig=0;
    std::cout<<"How many chickens do you own?"<<std::endl;
    std::cin>>chick;
    std::cout<<"How many piggies do you own?"<<std::endl;
    std::cin>>pig;
    std::cout<<"Your animals have "<< chick*2+pig*4<<" leggies."<< std::endl;

    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4
    int one=0, two=0, three=0, four=0, five=0;
    std::cout<<std::endl<<"Please give me 5 numbers, thanking."<<std::endl;
    std::cin>>one>>two>>three>>four>>five;
    std::cout<<"The sum of your stupid numbers is "<<one+two+three+four+five<<std::endl;
    std::cout<<"The average of your stupid numbers is "<<(one+two+three+four+five)/5<<std::endl;


    return 0;
}