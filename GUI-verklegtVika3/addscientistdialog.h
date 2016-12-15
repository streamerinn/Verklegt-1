#ifndef ADDSCIENTISTDIALOG_H
#define ADDSCIENTISTDIALOG_H

#include <QDialog>
#include <QString>
#include <iostream>
#include <QRegExp>
#include <QTime>
#include <QPixmap>
#include <QFileDialog>
#include <QIODevice>
#include <QByteArray>

#include "scientist.h"
#include "scientistservice.h"

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
    ScientistService scientistService;

};

#endif // ADDSCIENTISTDIALOG_H
