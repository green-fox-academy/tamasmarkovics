#ifndef GREENFOX_SPONSOR_H
#define GREENFOX_SPONSOR_H
#include <iostream>
#include <string>
using std::string;
#include "Person.h"

class Sponsor : public Person {

public:
    Sponsor();
    Sponsor(string name, int age, Gender gender, string company);

    void introduce() override;
    void hire();
    void getGoal() override;

private:
    string _company;
    int _hiredStudents;
};


#endif //GREENFOX_SPONSOR_H
