#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scientistservice.h"
#include "scientist.h"
#include "computer.h"
#include <vector>
#include <QString>

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

<<<<<<< HEAD

private:
=======

    void on_button_computers_clicked();

    void on_button_scientist_clicked();

    void on_button_linked_clicked();

private:

>>>>>>> e1ccf477d267d3bccd25666b8679585badab07f8

    Ui::MainWindow *ui;
    Computer *computers;
    Scientist *scientists;

};

#endif // MAINWINDOW_H
