#include "scientist.h"
#include <iostream>
#include <string>
#include <sstream>

Scientist::Scientist()
{
    _id = 0;
    _name = ' ';
    _gender = ' ';
    _dateOfBirth = 0;
    _dateOfDeath = 0;
}

Scientist::Scientist(int id, string name, string gender, int dateOfBirth, int dateOfDeath)
{
    _id = id;
    _name = name;
    _gender = gender;
    _dateOfBirth = dateOfBirth;
    _dateOfDeath = dateOfDeath;
}

Scientist::Scientist(string name, string gender, int dateOfBirth, int dateOfDeath)
{


    _name = name;
    _gender = gender;
    _dateOfBirth = dateOfBirth;
    _dateOfDeath = dateOfDeath;

}


int Scientist::getID()
{
    return _id;
}

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

string Scientist::getImage()
{
    return _image;
}

int Scientist::getDateOfDeath()
{
    return _dateOfDeath;
}

void Scientist::setID(int id)
{
    _id = id;
}

void Scientist::setName(string name)
{
    _name = name;
}

void Scientist::setImage (string image)
{
    _image = image;

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

