#include "performer.h"

Performer::Performer()
{

}

Performer::Performer(string name, string gender, int dateOfBirth, int dateOfDeath)
{
    _name = name;
    _gender = gender;
    _dateOfBirth = dateOfBirth;
    _dateOfDeath = dateOfDeath;
}
