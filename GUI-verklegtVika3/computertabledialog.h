#ifndef COMPUTERTABLEDIALOG_H
#define COMPUTERTABLEDIALOG_H

#include <QDialog>
#include <Qstring>
#include <vector>
#include <QDebug>

#include "computer.h"
#include "computerservice.h"
#include "addanewcomputerdialog.h"

namespace Ui {
class ComputerTableDialog;
}

class ComputerTableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ComputerTableDialog(QWidget *parent = 0);
    ~ComputerTableDialog();

private slots:
    void on_ComputerSearch_textChanged();

    void on_AddANewComputer_clicked();

private:
    ComputerService computerService;
    void displayAllComputers();
    void displayComputers(vector<Computer> computers);
    Ui::ComputerTableDialog *ui;
};

#endif // COMPUTERTABLEDIALOG_H
