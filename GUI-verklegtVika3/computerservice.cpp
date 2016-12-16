#include "computerservice.h"

//Constructor
ComputerService::ComputerService()
{
    setComputerVector();
}

//Stillir vektor af aftur þegar búið að stilla database
void ComputerService::setComputerVector()
{
    computers = data.computerDB();
}

vector<Computer> ComputerService::getComputers()
{
    return computers;
}

//Returns one computer into the vector.
//Returns one computer in the database.
void ComputerService::create(Computer computer)
{
    data.insertRow(computer);
    computers.push_back(computer);
    setComputerVector();
}

vector<Computer> ComputerService::searchComputerName(string computerName)
{
    return data.getName(computerName);
}

vector<Computer> ComputerService::searchType(const char type)
{
    return data.getType(type);
}

vector<Computer> ComputerService::searchYearOfBuild(int buildYear)
{
    return data.getYearBuilt(buildYear);
}

vector<Computer> ComputerService::searchBuilt(char built)
{
    return data.getBuilt(built);
}

void ComputerService::deleteComputer(int id)
{
    data.deleteComputer(id);
    setComputerVector();
}

void ComputerService::editComputer(string name,int id, int buildYear, int built, string type)
{
    data.editComputer(name, id, buildYear ,built, type);
    setComputerVector();
}

//Nær í ID hjá vísindamanni og nafn og notað til að linka
vector<Computer> ComputerService::getScientistID(int SID)
{
    vector<Computer> computersConnected;
    computersConnected = data.computersConnectedToScientist(SID);

    return computersConnected;
}
