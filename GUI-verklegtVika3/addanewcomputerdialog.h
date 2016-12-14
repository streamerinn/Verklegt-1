#ifndef ADDANEWCOMPUTERDIALOG_H
#define ADDANEWCOMPUTERDIALOG_H

#include <QDialog>
#include <QString>
#include <iostream>
#include <QRegExp>

#include "computer.h"
#include "computerservice.h"

namespace Ui {
class AddANewComputerDialog;
}

class AddANewComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddANewComputerDialog(QWidget *parent = 0);
    ~AddANewComputerDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddANewComputerDialog *ui;
    ComputerService computerservice;

};

#endif // ADDANEWCOMPUTERDIALOG_H
