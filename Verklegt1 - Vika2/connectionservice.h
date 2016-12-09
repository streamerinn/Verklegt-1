#ifndef CONNECTIONSERVICE_H
#define CONNECTIONSERVICE_H

#include <connectiondatabase.h>
#include "scientist.h"
#include<vector>


using namespace std;

class ConnectionService
{
public:
    // Consturctor
    ConnectionService();

    // Get föll
    void getIDs(vector<int> IDs);
    int getConnections();
    //vector<Scientist> idName();

private:
    ConnectionDataBase connections;
};

#endif // CONNECTIONSERVICE_H
