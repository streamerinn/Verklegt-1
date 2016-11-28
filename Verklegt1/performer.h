#ifndef PERFORMER_H
#define PERFORMER_H

#include <string>

using namespace std;

class Performer
{
public:
    Performer();   
    Performer(string name, int age);

    string getName()
    {
        return _name;
    }

    string getGender()
    {
        return _gender;
    }

    int getDateOfBirth() const
    {
        return _date_of_birth;
    }

    int getDateOfDeath() const
    {
        return _date_of_death;
    }

private:

    string _name;
    string _gender;
    int _date_of_birth;
    int _date_of_death;
};

#endif // PERFORMER_H
