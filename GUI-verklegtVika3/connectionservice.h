#ifndef CONNECTIONSERVICE_H
#define CONNECTIONSERVICE_H

#include <connectiondatabase.h>
#include "scientist.h"
#include <vector>
#include <algorithm>


using namespace std;

class ConnectionService
{
public:
    // Constructor
    ConnectionService();

    // Get functions
    void getIDs(vector<int> IDs);
    int getConnections();
    vector<Scientist> getConnectionIDs();

    // delete functions
    void deleteLink(int Compid, int sciID);

    // search scientist
    vector<Scientist> searchScientistName(string scientistName);
    vector<Scientist> searchComputerName(string computerName);


private:
    ConnectionDataBase connections;
    vector<Scientist> bothComputersAndScientists;
};

#endif // CONNECTIONSERVICE_H
