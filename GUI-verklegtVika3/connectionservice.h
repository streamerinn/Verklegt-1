#ifndef CONNECTIONSERVICE_H
#define CONNECTIONSERVICE_H

#include <connectiondatabase.h>
#include "scientist.h"
#include<vector>


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

    //delete functions
    void deleteLink(int Compid, int sciID);



private:
    ConnectionDataBase connections;
};

#endif // CONNECTIONSERVICE_H
