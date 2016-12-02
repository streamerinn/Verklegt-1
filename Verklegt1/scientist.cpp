#include "Scientist.h"
#include <iostream>
#include <string>
#include <sstream>

// Constructors
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

void Scientist::setName(string name)
{
    _name = name;
}

void Scientist::setGender(string gender)
{
    _gender = gender;
}

void Scientist::setDateOfBirth(int dateOfBirth)
{
    _dateOfBirth = dateOfBirth;
}

void Scientist::setDateOfDeath(int dateofDeath)
{
    _dateOfDeath = dateofDeath;
}

