#ifndef SCIENTIST_H
#define SCIENTIST_H

#include "scientist.h"

#include <string>
#include <vector>

using namespace std;

//entity klasi
class Scientist
{
public:

    //build föll
    Scientist();    // Default constructor
    string getName();
    string getSecondName();
    string getGender();
    int getDateOfBirth();
    int getDateOfDeath();
    void setName(string name);
    void setsecondName(string secondName);
    void setGender(string gender);
    void setDateOfBirth(int birth);
    void setDateOfDeath(int death);

    Scientist(string name, string gender, int dateOfBirth, int dateOfDeath);

    //les inn upplýsingar um Scientists
    //void readScientists(vector <Scientist> &scientists);

private:

    vector<Scientist> _scientists;
    string _name;
    string _secondname;
    string _gender;
    int _dateOfBirth;
    int _dateOfDeath;
};

#endif // SCIENTIST_H
