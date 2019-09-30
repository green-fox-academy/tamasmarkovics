#include "Cohort.h"

Cohort::Cohort(string name)
{
    _name = name;
    _students[0];
    _mentors[0];
}

void Cohort::addStudent(Student* studentPointer)
{
    _students.push_back(studentPointer);
}
void Cohort::addMentor(Mentor* mentorPointer)
{
    _mentors.push_back(mentorPointer);
}
void Cohort::info()
{
    std::cout << "The " << _name << " cohort has " << _students.size() << " students and " << _mentors.size() <<
    " mentors." << std::endl;
}