#include "computer.h"
#include <string>
#include <iostream>
#include <sstream>

Computer::Computer()
{
    _ID = 0;
    _computerName = ' ';
    _type = ' ';
    _yearBuilt = 0;
    _built = ' ';
}

Computer::Computer(int ID, string computerName, char type, int yearBuilt, string built)
{
    _ID = ID;
    _computerName = computerName;
    _type = type;
    _yearBuilt = yearBuilt;
    _built = built;
}

int Computer::getID()
{
    return _ID;
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

string Computer::getBuilt()
{
    return _built;
}

void Computer::setID(int ID)
{
    _ID = ID;
}

void Computer::setName(string computerName)
{
    _computerName = computerName;
}

void Computer::setType(string type)
{
    _type = type;
}

void Computer::setYearBuilt(int yearbuilt)
{
    _yearBuilt = yearbuilt;
}

void Computer::setBuilt(string built)
{
    _built = built;
}
