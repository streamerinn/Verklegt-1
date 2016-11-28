#ifndef PERFORMER_H
#define PERFORMER_H

#include <string>
#include <vector>

using namespace std;

class Performer
{
public:

    //build föll
    Performer();
    Performer(string name, string gender, int dateOfBirth, int dateOfDeath);

    //les inn upplýsingar um Scientists
    void readScientists(vector <Performer> &performers);

    //get föll
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
        return _dateOfBirth;
    }

    int getDateOfDeath() const
    {
        return _dateOfDeath;
    }

private:

    string _name;
    string _gender;
    int _dateOfBirth;
    int _dateOfDeath;
};

#endif // PERFORMER_H
