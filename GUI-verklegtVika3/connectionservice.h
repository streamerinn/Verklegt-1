#ifndef CONNECTIONSERVICE_H
#define CONNECTIONSERVICE_H

#include <connectiondatabase.h>
#include <vector>
#include <algorithm>

#include "scientist.h"

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
    bool insertRow(vector<int> IDs);

    // delete functions
    void deleteLink(int Compid, int sciID);

    // search scientist
    vector<Scientist> searchScientistName(string scientistName);
    vector<Scientist> searchComputerName(string computerName);

    void getConnectionVector();


private:
    ConnectionDataBase connections;
    vector<Scientist> bothComputersAndScientists;
};

#endif // CONNECTIONSERVICE_H
