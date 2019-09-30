#ifndef GREENFOX_PERSON_H
#define GREENFOX_PERSON_H
#include <iostream>
#include <string>
using std::string;

class Person {
public:
    Person(string name, int age, string gender);
    Person();
    virtual void introduce();
    virtual void getGoal();
    string _name;
    int _age;
    string _gender;
private:

};


#endif //GREENFOX_PERSON_H
