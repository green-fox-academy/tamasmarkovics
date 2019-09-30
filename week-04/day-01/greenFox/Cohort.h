#ifndef GREENFOX_COHORT_H
#define GREENFOX_COHORT_H
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
#include "Person.h"
#include "Student.h"
#include "Mentor.h"


class Cohort{

public:
    Cohort(string name);

    void addStudent(Student*);
    void addMentor(Mentor*);
    void info();

private:
    string _name;
    vector<Student*> _students;
    vector<Mentor*> _mentors;

};


#endif //GREENFOX_COHORT_H
