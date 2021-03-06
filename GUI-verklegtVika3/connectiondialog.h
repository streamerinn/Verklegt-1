#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include "computer.h"
#include "scientist.h"
#include "scientistservice.h"
#include "computerservice.h"
#include "connectionservice.h"
#include "addconnection.h"
#include "deleteconnection.h"

#include <QDialog>
#include <vector>
#include <QString>
#include <QDebug>

namespace Ui {
class ConnectionDialog;
}

class ConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionDialog(QWidget *parent = 0);
    ~ConnectionDialog();

private slots:
    void on_SearchScientistName_textChanged();

    void on_SearchComputerName_textChanged();

    void on_deleteButton_clicked();

    void on_addButton_clicked();

private:
    Ui::ConnectionDialog *ui;

    ScientistService scientistService;
    ComputerService computerService;
    ConnectionService connectionService;

    void displayAllConnections();
    void displayScientists(vector<Scientist> scientists);

};

#endif // CONNECTIONDIALOG_H
