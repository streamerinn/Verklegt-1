#include "performer.h"

Performer::Performer()
{
    _name = ' ';
    _gender = ' ';
    _dateOfBirth = 0;
    _dateOfDeath = 0;
}

Performer::Performer(string name, string gender, int dateOfBirth, int dateOfDeath)
{
    _name = name;
    _gender = gender;
    _dateOfBirth = dateOfBirth;
    _dateOfDeath = dateOfDeath;
}
