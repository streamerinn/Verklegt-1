#ifndef SCIENTIST_H
#define SCIENTIST_H

#include "scientist.h"

#include <string>
#include <vector>

using namespace std;

class Scientist
{
public:
    // constructors
    Scientist();
    Scientist(int id, string name, string gender, int dateOfBirth, int dateOfDeath);
    Scientist(string name, string gender, int dateOfBirth, int dateOfDeath);

    // get functions
    int getID();
    string getName();
    string getGender();
    string getImage();
    int getDateOfBirth();
    int getDateOfDeath();

    // set functions
    void setID(int id);
    void setName(string name);
    void setGender(string gender);
    void setDateOfBirth(int birth);
    void setDateOfDeath(int death);
    void setImage (string image);

private:
    vector<Scientist> _scientists;
    int _id;
    string _name;
    string _gender;
    int _dateOfBirth;
    int _dateOfDeath;
    string _image;

};

#endif // SCIENTIST_H
