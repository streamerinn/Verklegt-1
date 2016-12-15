#include "deleteconnection.h"
#include "ui_deleteconnection.h"
#include <QPixmap>

DeleteConnection::DeleteConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteConnection)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    QPixmap pix(":/images/deleteConnection.png");
    ui->deletePic->setPixmap(pix.scaled(300,100));
}

DeleteConnection::~DeleteConnection()
{
    delete ui;
}


void DeleteConnection::on_deleteButton_clicked()
{
    QString sciID = ui->insertSciID->text();
    QString compID = ui->insertCompID->text();

    if (sciID.isEmpty())
    {
        ui->errorCheck->setText("<span style = 'color:red'>Connection failed!</span>");
    }

    if (compID.isEmpty())
    {
        ui->errorCheck->setText("<span style = 'color:red'>Connection failed!</span>");
    }
    else
    {
        int tempSci = sciID.toInt();
        int tempComp = compID.toInt();

        connectionService.deleteLink(tempComp,tempSci);
        close();
    }
}
