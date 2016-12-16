#include "addconnection.h"
#include "ui_addconnection.h"
#include "connectiondialog.h"

#include <string>
#include <QString>
#include <QPixmap>

AddConnection::AddConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddConnection)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    QPixmap pix(":/images/addConnection.png");
    ui->connectionPic->setPixmap(pix.scaled(300,100));
    on_idTable_activated();

    QString stylesheet = "::section{"
                             "spacing: 10px;"
                            "background-color: gray;"
                            "color: white;}";
    ui->idTable->horizontalHeader()->setStyleSheet(stylesheet);
    ui->idTable->verticalHeader()->setStyleSheet(stylesheet);



}

AddConnection::~AddConnection()
{
    delete ui;
}

void AddConnection::on_addButton_clicked()
{
    vector<int> idVector;

    QString SciID  = ui->insertSciID->text();
    QString CompID = ui->insertCompID->text();

    if (SciID.isEmpty())
    {
        ui->addCheck->setText("<span style = 'color:red'>Connection failed!</span>");
    }

    if (CompID.isEmpty())
    {
        ui->addCheck->setText("<span style = 'color:red'>Connection failed!</span>");
    }
    else
    {
        int newSciID = SciID.toInt();
        int newCompID = CompID.toInt();

        idVector.push_back(newSciID);
        idVector.push_back(newCompID);

        bool success = connectionService.insertRow(idVector);

        if(success)
        {
            ui->addCheck->setText("Connection added");
        }

        close();
    }
}


void AddConnection::on_idTable_activated()
{
    vector<Scientist> scientistInfo = scientistServie.getScientists();
    vector<Computer> computerInfo = computerService.getComputers();

    ui->idTable->setRowCount(scientistInfo.size());
    ui->idTable->setRowCount(computerInfo.size());


    for(unsigned int i = 0; i < scientistInfo.size(); i++)
    {
        ui->idTable->setItem(i, 0, new QTableWidgetItem(QString::number(scientistInfo[i].getID())));
        ui->idTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(scientistInfo[i].getName())));

    }

    for(unsigned int i = 0; i < computerInfo.size(); i++)
    {
        ui->idTable->setItem(i, 2, new QTableWidgetItem(QString::number(computerInfo[i].getID())));
        ui->idTable->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(computerInfo[i].getComputerName())));

    }
}

