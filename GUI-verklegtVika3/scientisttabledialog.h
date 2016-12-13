#ifndef SCIENTISTTABLEDIALOG_H
#define SCIENTISTTABLEDIALOG_H

#include <QDialog>
#include <Qstring>
#include <vector>
#include <QDebug>

#include "scientist.h"
#include "scientistservice.h"
#include "addscientistdialog.h"

namespace Ui {
class ScientistTableDialog;
}

class ScientistTableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScientistTableDialog(QWidget *parent = 0);
    ~ScientistTableDialog();

    void on_comboBox_currentIndexChanged(int index);

private slots:
    void on_AddANewScientist_clicked();

    void on_ScientistSearch_textChanged();

private:
    void displayAllScientists();
    void displayScientists(vector<Scientist> scientists);
    ScientistService scientistService;

    Ui::ScientistTableDialog *ui;
};

#endif // SCIENTISTTABLEDIALOG_H
