#include "computerservice.h"

//Constructor
ComputerService::ComputerService()
{
    setComputerVector();
}

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

vector<Computer> ComputerService::searchRandomComputer()
{
    vector<Computer> temp3;
    srand(time(0));
                    //Creates random numbers with the help of time.
                   // The reason to use %(scientist.size() - 1) is to get all the range from the vector.
    temp3.push_back(computers[1+(rand()%(computers.size() - 1))]);

    return temp3;
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

vector<Computer> ComputerService::getScientistID(int SID)
{
    vector<Computer> computersConnected;
    computersConnected = data.computersConnectedToScientist(SID);

    return computersConnected;
}
