#ifndef GREENFOX_MENTOR_H
#define GREENFOX_MENTOR_H
#include <iostream>
#include <string>
using std::string;
#include "Person.h"

enum class Level {
    JUNIOR,
    SENIOR,
    INTERMEDIATE
};

class Mentor : public Person {

public:
    Mentor(string name, int age, Gender gender, Level level);
    Mentor();

    void getGoal() override;
    void introduce() override;

private:
    Level _level;
};


#endif //GREENFOX_MENTOR_H
