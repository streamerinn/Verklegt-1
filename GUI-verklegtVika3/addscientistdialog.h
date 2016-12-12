#ifndef ADDSCIENTISTDIALOG_H
#define ADDSCIENTISTDIALOG_H

#include <QDialog>
#include <QString>
#include <iostream>

using namespace std;

namespace Ui
{
class AddScientistDialog;
}

class AddScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddScientistDialog(QWidget *parent = 0);
    ~AddScientistDialog();

private slots:
    void on_AddScientist_clicked();

private:
    Ui::AddScientistDialog *ui;
};

#endif // ADDSCIENTISTDIALOG_H
