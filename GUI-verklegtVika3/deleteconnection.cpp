#include "deleteconnection.h"
#include "ui_deleteconnection.h"

DeleteConnection::DeleteConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteConnection)
{
    ui->setupUi(this);
}

DeleteConnection::~DeleteConnection()
{
    delete ui;
}


void DeleteConnection::on_deleteButton_clicked()
{
    QString sciID = ui->insertSciID->text();
    QString compID = ui->insertCompID->text();

    int tempSci = sciID.toInt();
    int tempComp = compID.toInt();

    qDebug() << tempSci;
    qDebug() << tempComp;

    connectionService.deleteLink(tempComp,tempSci);
}
