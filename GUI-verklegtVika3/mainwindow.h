#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scientistservice.h"
#include "scientist.h"
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

private:
    void displayAllScientists();
    void displayScientists(vector<Scientist> scientists);
    ScientistService scientistService;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
