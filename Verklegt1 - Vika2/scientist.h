#ifndef SCIENTIST_H
#define SCIENTIST_H

#include "scientist.h"

#include <string>
#include <vector>

using namespace std;

class Scientist
{
public:
    // constructorar
    Scientist();
    Scientist(int id, string name, string gender, int dateOfBirth, int dateOfDeath);

    // get föll
    int getID();
    string getName();
    string getGender();
    int getDateOfBirth();
    int getDateOfDeath();

    // set föll
    void setID(int id);
    void setName(string name);
    void setsecondName(string secondName);
    void setGender(string gender);
    void setDateOfBirth(int birth);
    void setDateOfDeath(int death);

private:
    vector<Scientist> _scientists;
    int _id;
    string _name;
    string _gender;
    int _dateOfBirth;
    int _dateOfDeath;

};

#endif // SCIENTIST_H
