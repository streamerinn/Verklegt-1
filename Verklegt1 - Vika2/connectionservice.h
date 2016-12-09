#ifndef CONNECTIONSERVICE_H
#define CONNECTIONSERVICE_H

#include <connectiondatabase.h>
#include "scientist.h"
#include<vector>


using namespace std;

class ConnectionService
{
public:
    ConnectionService();

    void getIDs(vector<int> IDs);
    int getConnections();

private:
    ConnectionDataBase connections;
};

#endif // CONNECTIONSERVICE_H
