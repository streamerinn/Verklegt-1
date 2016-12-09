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

    void create(Computer computer);

    vector<Computer> getComputers();
    vector<Computer> getComputersAlpha();
    vector<Computer> getComputersReversedAlpha();
    vector<Computer> getComputersYoung();
    vector<Computer> getComputersOld();
    vector<Computer> getComputersBuiltOrNot();
    vector<Computer> getComputersID();

    vector<Computer> searchComputerName(string name);
    vector<Computer> searchYearOfBuild(int buildYear);
    vector<Computer> searchType(const char type);
    vector<Computer> searchBuilt(char built);

    vector<Computer> searchRandomComputer();


    int searchID(string computerName);

    // sendir ID og sækir Tölvur connectaðar við ID-ið
    vector<Computer> getScientistID(int SID);

    int getConnections(); // returns how many connections there are

    void deleteComputer(int id);
    void editComputer(string name, int id, int buildYear,int built, string type);

private:
    vector<Computer> computers;
    ComputerDatabase data;
};

#endif // COMPURSERVICE_H
