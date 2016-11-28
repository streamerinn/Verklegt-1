#ifndef PERFORMER_H
#define PERFORMER_H

#include <string>

using namespace std;

class Performer
{
public:
    Performer();   
    Performer(string name, string gender, int dateOfBirth, int dateOfDeath);
    void readScientists(vector <Performer> &performers);

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
