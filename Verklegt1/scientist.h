#ifndef SCIENTIST_H
#define SCIENTIST_H

#include "scientist.h"

#include <string>
#include <vector>

using namespace std;

class Scientist
{
public:

    Scientist();
    string getName();
    string getGender();
    int getDateOfBirth();
    int getDateOfDeath();
    void setName(string name);
    void setsecondName(string secondName);
    void setGender(string gender);
    void setDateOfBirth(int birth);
    void setDateOfDeath(int death);

    Scientist(string name, string gender, int dateOfBirth, int dateOfDeath);

private:

    vector<Scientist> _scientists;
    string _name;
    string _gender;
    int _dateOfBirth;
    int _dateOfDeath;

};

#endif // SCIENTIST_H
