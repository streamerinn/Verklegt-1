#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>
#include <vector>

using namespace std;

class Scientist
{
public:

    //build föll
    Scientist();    // Default constructor
    string getName();
    string getGender();
    int getDateOfBirth();
    int getDateOfDeath();

    Scientist(string name, string gender, int dateOfBirth, int dateOfDeath);

    //les inn upplýsingar um Scientists
    //void readScientists(vector <Scientist> &scientists);

private:

    string _name;
    string _gender;
    int _dateOfBirth;
    int _dateOfDeath;
};

#endif // SCIENTIST_H
