#ifndef MAINWINDOW_H
#define MAINWINDOW_H


//#include "scientistservice.h"
#include "scientist.h"
#include "computer.h"
#include "scientisttabledialog.h"
#include "computertabledialog.h"
#include "connectiondialog.h"

#include <vector>
#include <QString>
#include <QMainWindow>

using namespace std;

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_button_computers_clicked();

    void on_button_scientist_clicked();

    void on_button_linked_clicked();

    void on_button_link_clicked();

private:
    //ScientistTableDialog *scientistTable;

    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
