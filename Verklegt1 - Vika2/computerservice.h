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

    // Display föll
    vector<Computer> getComputers();
    vector<Computer> getComputersAlpha();
    vector<Computer> getComputersReversedAlpha();
    vector<Computer> getComputersYoung();
    vector<Computer> getComputersOld();
    vector<Computer> getComputersBuiltOrNot();
    vector<Computer> getComputersID();

    // search föll
    vector<Computer> searchComputerName(string name);
    vector<Computer> searchYearOfBuild(int buildYear);
    vector<Computer> searchType(const char type);
    vector<Computer> searchBuilt(char built);
    vector<Computer> searchRandomComputer();

    // sendir ID og sækir Tölvur connectaðar við ID-ið
    vector<Computer> getScientistID(int SID);

    // sækir fjölda connections
    int getConnections();

    // Breytir upplýsingum í database
    void deleteComputer(int id);
    void editComputer(string name, int id, int buildYear,int built, string type); // sendir nýjar upplýsingar um computer database

private:
    vector<Computer> computers;
    ComputerDatabase data;
};

#endif // COMPURSERVICE_H
