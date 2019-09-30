#ifndef GREENFOX_STUDENT_H
#define GREENFOX_STUDENT_H
#include <iostream>
#include <string>
using std::string;
#include "Person.h"


class Student : public Person {
public:

    Student(string name, int age, Gender gender, string previousOrg);
    Student();

    void getGoal() override;
    void introduce() override;
    void skipDays(int numberOfDays);

protected:
    string _previousOrganization;
    int _skippedDays;
};


#endif //GREENFOX_STUDENT_H
