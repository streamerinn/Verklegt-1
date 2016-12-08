#include "connectionservice.h"
#include <iostream> // eyða

ConnectionService::ConnectionService()
{

}

void ConnectionService::getIDs(vector<int> IDs)
{
    cout << "service test" << IDs[0] << IDs[1] << endl;

    connections.insertRow(IDs);
}

int ConnectionService::getConnections()
{
    return connections.countConnections();
}
