#include <iostream>

int main() {

    //Fav number
    int z=8;
    std::cout << "My favourite number is: "<< z << std::endl<< std::endl;

    //Swap
    int a = 123;
    int b = 526;
    int temp;
    temp=a;
    a=b;
    b=temp;
    std::cout << a << std::endl;
    std::cout << b << std::endl<<std::endl;

    //BMI
     double massInKg = 81.2;
     double heightInM = 1.78;
     // Print the Body mass index (BMI) based on these values
    std::cout<<massInKg/(heightInM*heightInM)<<std::endl<<std::endl;

    //define basic info
    std::string name="Tamas";
    std::cout<<name<< std::endl;
    int age=24;
    std::cout<<age<< std::endl;
    double h=1.78;
    std::cout<<h<< std::endl;
    bool is_married=0;
    std::cout<<is_married<< std::endl;



    return 0;
}
