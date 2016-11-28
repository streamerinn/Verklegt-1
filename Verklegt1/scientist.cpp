#include "Scientist.h"
#include <iostream>
#include <string>

Scientist::Scientist()
{
    _name = ' ';
    _gender = ' ';
    _dateOfBirth = 0;
    _dateOfDeath = 0;
}

Scientist::Scientist(string name, string gender, int dateOfBirth, int dateOfDeath)
{
    _name = name;
    _gender = gender;
    _dateOfBirth = dateOfBirth;
    _dateOfDeath = dateOfDeath;
}

//get föll
string Scientist::getName()
{
    return _name;
}

string Scientist::getGender()
{
    return _gender;
}

int Scientist::getDateOfBirth()
{
    return _dateOfBirth;
}

int Scientist::getDateOfDeath()
{
    return _dateOfDeath;
}
