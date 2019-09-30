#include "Mentor.h"


void Mentor::getGoal()
{
    std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}

void Mentor::introduce()
{
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << (_gender == Gender::MALE ? "male" : "female")
    << " " << (_level == Level::SENIOR ? "senior" : _level == Level::JUNIOR ? "junior" : "intermediate") <<" mentor." << std::endl;
}

Mentor::Mentor(string name, int age, Gender gender, Level level)
{
    _name = name;
    _age = age;
    _gender = gender;
    _level = level;
}

Mentor::Mentor()
{
    _name = "Jane Doe";
    _age = 30;
    _gender = Gender::FEMALE;
    _level = Level::INTERMEDIATE;
}