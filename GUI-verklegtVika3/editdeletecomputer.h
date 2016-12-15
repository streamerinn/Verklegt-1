#ifndef EDITDELETECOMPUTER_H
#define EDITDELETECOMPUTER_H

#include <QDialog>
#include <Qstring>
#include <vector>
#include <QDebug>
#include <QTableWidget>

#include "computer.h"
#include "computerservice.h"

namespace Ui {
class EditDeleteComputer;
}

class EditDeleteComputer : public QDialog
{
    Q_OBJECT

public:
    explicit EditDeleteComputer(QWidget *parent = 0);
    ~EditDeleteComputer();

private slots:
    void on_editComputer_clicked();
    void on_searchComputer_textChanged();
    void on_Names_cellClicked(int row, int column);
    void on_Delete_clicked();

private:
    Ui::EditDeleteComputer *ui;
    void displayAllCpu();
    void displayCpu(vector<Computer> computers);
    ComputerService computerservice;
};

#endif // EDITDELETECOMPUTER_H
