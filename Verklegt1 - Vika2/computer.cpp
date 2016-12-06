#include "computer.h"
#include <string>
#include <iostream>
#include <sstream>

Computer::Computer()
{
    _id = 0;
    _computerName = ' ';
    _type = ' ';
    _yearBuilt = 0;
    _built = 0;
}

Computer::Computer(int id, string computerName, string type, int yearBuilt, int built)
{
    _id = id;
    _computerName = computerName;
    _type = type;
    _yearBuilt = yearBuilt;
    _built = built;
}

int Computer::getID()
{
    return _id;
}

string Computer::getComputerName()
{
    return _computerName;
}

string Computer::getType()
{
    return _type;
}

int Computer::getYearBuilt()
{
    return _yearBuilt;
}

int Computer::getBuilt()
{
    return _built;
}

void Computer::setID(int id)
{
    _id = id;
}

void Computer::setName(string computerName)
{
    _computerName = computerName;
}

void Computer::setType(char type)
{
    _type = type;
}

void Computer::setYearBuilt(int yearbuilt)
{
    _yearBuilt = yearbuilt;
}

void Computer::setBuilt(int built)
{
    _built = built;
}
