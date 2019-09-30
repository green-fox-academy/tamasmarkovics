#ifndef GREENFOX_PERSON_H
#define GREENFOX_PERSON_H
#include <iostream>
#include <string>
using std::string;

enum class Gender {
    MALE,
    FEMALE
};

class Person {

public:
    Person(string name, int age, Gender gender);
    Person();

    virtual void introduce();
    virtual void getGoal();

protected:
    string _name;
    int _age;
    Gender _gender;

private:

};


#endif //GREENFOX_PERSON_H
