#ifndef GREENFOX_MENTOR_H
#define GREENFOX_MENTOR_H
#include <iostream>
#include <string>
using std::string;
#include "Person.h"


class Mentor : public Person {

public:
    Mentor(string name, int age, string gender, string level);
    Mentor();

    void getGoal() override;
    void introduce() override;

private:
    string _level;
};


#endif //GREENFOX_MENTOR_H
