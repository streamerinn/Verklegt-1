#include "addconnection.h"
#include "ui_addconnection.h"
#include "connectiondialog.h"

#include <string>
#include <QString>

AddConnection::AddConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddConnection)
{
    ui->setupUi(this);
}

AddConnection::~AddConnection()
{
    delete ui;
}


void AddConnection::on_addButton_clicked()
{
    vector<int> idVector;

    QString SciID  = ui->ScientistID->text();
    QString CompID = ui->ComputerID->text();

    if (SciID.isEmpty())
    {
        qDebug() << "scientist id missing";
        return;
    }

    if (CompID.isEmpty())
    {
        qDebug() << "computer id missing";
        return;
    }

    int newSciID = SciID.toInt();
    int newCompID = CompID.toInt();

    idVector.push_back(newSciID);
    idVector.push_back(newCompID);

    bool success = connectionService.insertRow(idVector);

    if(success)
    {
        qDebug() << "Connection added";
    }
    else
    {
        qDebug() << "Connection add error";
    }
}
