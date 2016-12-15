#ifndef EDITDELETSCIENTIST_H
#define EDITDELETSCIENTIST_H

#include <QDialog>
#include <Qstring>
#include <vector>
#include <QDebug>
#include <QTableWidget>

#include "scientist.h"
#include "scientistservice.h"
#include "addscientistdialog.h"

namespace Ui {
class EditDeletScientist;
}

class EditDeletScientist : public QDialog
{
    Q_OBJECT

public:
    explicit EditDeletScientist(QWidget *parent = 0);
    ~EditDeletScientist();

private slots:
    void on_ScientistSearch_textChanged();
    void on_Names_cellClicked(int row, int column);
    void on_editScientist_clicked();
    void on_Delete_clicked();

private:
    Ui::EditDeletScientist *ui;
    void displayAllScientists();
    void displayScientists(vector<Scientist> scientists);
    ScientistService scientistService1;
};

#endif // EDITDELETSCIENTIST
