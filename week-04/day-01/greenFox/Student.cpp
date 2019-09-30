#include "Student.h"



void Student::getGoal()
{
    std::cout << "My goal is: Be a junior software developer." << std::endl;
}
void Student::introduce()
{
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << (_gender == Gender::MALE ? "male" : "female") << " from " << _previousOrganization <<
    "who skipped " << _skippedDays << " days from the course already." << std::endl;
}

Student::Student(string name, int age, Gender gender, string previousOrg)
{
    _name = name;
    _age = age;
    _gender = gender;
    _previousOrganization = previousOrg;
    _skippedDays = 0;
}

Student::Student()
{
    _name = "Jane Doe";
    _age = 30;
    _gender = Gender::FEMALE;
    _previousOrganization = "The School of Life";
    _skippedDays = 0;
}

void Student::skipDays(int numberOfDays)
{
    _skippedDays += numberOfDays;
}