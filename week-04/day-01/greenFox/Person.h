#ifndef GREENFOX_PERSON_H
#define GREENFOX_PERSON_H
#include <iostream>
#include <string>
using std::string;

class Person {
public:
    Person(string name, int age, string gender);
    Person();
    void introduce();
    void getGoal();
private:
    string _name;
    int _age;
    string _gender;
};


#endif //GREENFOX_PERSON_H
