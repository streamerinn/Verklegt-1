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
    qDebug() << Compid;
    qDebug() << sciID;
    connections.deleteLink(Compid, sciID);
}

vector<Scientist> ConnectionService::getConnectionIDs()
{
    vector<Scientist> connectionIDs;

    connectionIDs = connections.getConnectionIDs();

    return connectionIDs;
}

vector<Scientist> ConnectionService::searchScientistName(string scientistName)
{
    vector<Scientist> returnScientist;
    string name;

    for(unsigned int i = 0; i < bothComputersAndScientists.size(); i += 2)
    {
        name = bothComputersAndScientists[i].getName();
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        transform(scientistName.begin(), scientistName.end(), scientistName.begin(), ::tolower);
        if(name.find(scientistName) !=string::npos)
        {
            returnScientist.push_back(bothComputersAndScientists[i]);
            returnScientist.push_back(bothComputersAndScientists[i+1]);
        }
    }
    return returnScientist;
}

vector<Scientist> ConnectionService::searchComputerName(string computerName)
{
    vector<Scientist> returnComputer;
    string name;

    for(unsigned int i = 1; i < bothComputersAndScientists.size(); i += 2)
    {
        name = bothComputersAndScientists[i].getName();
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        transform(computerName.begin(), computerName.end(), computerName.begin(), ::tolower);
        if(name.find(computerName) !=string::npos)
        {
            returnComputer.push_back(bothComputersAndScientists[i-1]);
            returnComputer.push_back(bothComputersAndScientists[i]);
        }
    }
    return returnComputer;
}


bool ConnectionService::insertRow(vector<int> IDs)
{
    bool success = connections.insertRow(IDs);

    if(success)
    {
        return true;
    }
    return false;
}
