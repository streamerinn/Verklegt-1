#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include "computer.h"
#include "scientist.h"
#include "scientistservice.h"
#include "computerservice.h"

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
    void on_SearchScientistName_textChanged(const QString &arg1);

private:
    Ui::ConnectionDialog *ui;

    ScientistService scientistService;
    ComputerService computerService;

    void displayAllConnections();
    void displayScientists(vector<Scientist> scientists);
};

#endif // CONNECTIONDIALOG_H
