#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scientist.h"
#include "computer.h"
#include "scientisttabledialog.h"
#include "computertabledialog.h"
#include "connectiondialog.h"
#include "aboutdialog.h"
#include "connectionservice.h"
#include "musicdialog.h"

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

    bool darktheme;

private slots:

    void on_button_computers_clicked();

    void on_button_scientist_clicked();

    void on_button_link_clicked();

    void on_actionAbout_triggered();

    void on_toggle_theme_clicked();

    void displayClock();

    void on_toolButton_clicked();

private:
    ScientistService sService;
    ComputerService cService;
    ConnectionService coService;

    void stats();

    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
