#ifndef COMPURSERVICE_H
#define COMPURSERVICE_H

#include "computer.h"
#include "computerdatabase.h"

#include <vector>
#include <algorithm>
#include <QString>
#include <cstdlib>
#include <ctime>


using namespace std;

class ComputerService
{
public:
    ComputerService();

    void setComputerVector();

    void create(Computer computer);

    // Display functions
    vector<Computer> getComputers();
    vector<Computer> getComputersBuiltOrNot();
    vector<Computer> getComputersID();

    // search functions
    vector<Computer> searchComputerName(string name);
    vector<Computer> searchYearOfBuild(int buildYear);
    vector<Computer> searchType(const char type);
    vector<Computer> searchBuilt(char built);
    vector<Computer> searchRandomComputer();

    // Sends an ID and retrieves computers connected to the ID.
    vector<Computer> getScientistID(int SID);

    // Retrieves how many connections there are between scientists and computers.
    int getConnections();

    // Changes information in the database.
    void deleteComputer(int id);
    void editComputer(string name, int id, int buildYear,int built, string type); // sendir nýjar upplýsingar um computer database

private:
    vector<Computer> computers;
    ComputerDatabase data;
};

#endif // COMPURSERVICE_H
