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
    QPixmap pix("/Users/irisdogg/Desktop/Verklegt-1/GUI-verklegtVika3/addConnection.png");
    ui->connectionPic->setPixmap(pix.scaled(300,100));
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

