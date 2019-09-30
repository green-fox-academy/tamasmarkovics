#include "Sponsor.h"


Sponsor::Sponsor()
{
    _name = "Jane Doe";
    _age = 30;
    _gender = Gender::FEMALE;
    _company = "Google";
    _hiredStudents = 0;
}

Sponsor::Sponsor(string name, int age, Gender gender, string company)
{
    _name = name;
    _age = age;
    _gender = gender;
    _company = company;
    _hiredStudents = 0;
}

void Sponsor::introduce()
{
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << (_gender == Gender::MALE ? "male" : "female") << " who represents " << _company <<
    " and hired " << _hiredStudents << " students so far." << std::endl;
}

void Sponsor::hire()
{
    _hiredStudents++;
}

void Sponsor::getGoal()
{
    std::cout << "My goal is: Hire brilliant junior software developers." << std::endl;
}
