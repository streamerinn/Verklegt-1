#include "connectionservice.h"

//Constructor
ConnectionService::ConnectionService()
{

}

void ConnectionService::getIDs(vector<int> IDs)
{
    connections.insertRow(IDs);
}

int ConnectionService::getConnections()
{
    return connections.countConnections();
}


void ConnectionService::deleteLink(int Compid, int sciID)
{
    connections.deleteLink(Compid, sciID);
}

