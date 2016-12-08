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

    vector<Computer> searchComputerName(string name);
    vector<Computer> searchYearOfBuild(int buildYear);
    vector<Computer> searchType(const string type);
    vector<Computer> searchBuilt(const char built);

    vector<Computer> searchRandomComputer();


    int searchID(string computerName);

<<<<<<< HEAD
=======
    int getConnections(); // returns how many connections there are

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 31e8d7e12cc18684c2e282c66aa521b99a372330
>>>>>>> 98210d66be575f87a67ee17cd6cd7e96bec419ff
    void deleteComputer(int id);
    void editComputer(int id);

private:
    vector<Computer> computers;
    ComputerDatabase data;
};

#endif // COMPURSERVICE_H
