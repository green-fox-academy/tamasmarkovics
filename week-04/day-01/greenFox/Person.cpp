#include "Person.h"

void Person::introduce()
{
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << (_gender == Gender::MALE ? "male" : "female") << "." << std::endl;
}
void Person::getGoal()
{
    std::cout << "My goal is: Live for the moment!" << std::endl;
}

Person::Person(string name, int age, Gender gender) : _name(name), _age(age), _gender(gender) {}

Person::Person() {
    _name = "Jane Doe";
    _age = 30;
    _gender = Gender::FEMALE;
}