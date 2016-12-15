#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMenuBar>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /**** Tooltips ****/
    ui->button_computers->setToolTip("<font color = '#245066'><b>Add/Remove computer(s)</b></font>");
    ui->button_scientist->setToolTip("<font color = '#245066'><b>Add/Edit scientist(s)</b></font>");
    ui->button_link->setToolTip("<font color = '#245066'><b>Manage connection(s)</b></font>");
    //ui->toggle_theme->setToolTip("Change theme")

    /**** Digital klukka ****/
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT (displayClock()));
    timer->start();

    /**** Breyta lita þemu ****/
    darktheme = false;
    stats();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_computers_clicked()
{
    //Computer computers;
    //computers->show();
    //this->hide();

    ComputerTableDialog computerTableDialog(this);
    computerTableDialog.exec();
}

void MainWindow::on_button_scientist_clicked()
{

    //Scientist scientists;
    //scientists->show();
    //this->hide();

    ScientistTableDialog scientistTableDialog(this);
    scientistTableDialog.exec();

    //scientistTable = new ScientistTableDialog(this);
    //scientistTable->show();
    //this->hide();

}

void MainWindow::on_button_link_clicked()
{
    ConnectionDialog connectionDialog(this);
    connectionDialog.exec();
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog aboutDialog(this);
    aboutDialog.exec();
}

void MainWindow::on_toggle_theme_clicked()
{
    if(!darktheme)
    {
        this->setStyleSheet("*{background-color: rgb(36, 36, 36); color: rgb(249, 249, 249);}"
                            "QHeaderView::section {background-color: rgb(36, 36, 36); color: rgb(249, 249, 249);}"
                            "QTableWidget QTableCornerButton::section {background-color: rgb(36, 36, 36); color: rgb(249, 249, 249);}"
                            "QMenu {selection-background-color: rgb(80, 238, 255);}"
                            "QPushButton {color: rgb(80, 238, 255); background-color: rgb(36, 36, 36);}");
        darktheme = true;
    }
    else
    {
        this->setStyleSheet("");
        darktheme = false;
    }

}

void MainWindow::stats()
{
    size_t dead;
    vector<Scientist> males = sService.searchGender('M');
    vector<Scientist> females = sService.searchGender('F');
    vector<Scientist> alive = sService.searchDateOfDeath(0);
    vector<Scientist> total = sService.getScientists();
    vector<Computer> computers = cService.getComputers();

    int totalConnections = coService.getConnections();
    dead = total.size() - alive.size();

    ui->listStats->clear();
    if(males.size() == 1)
        ui->listStats->addItem(QString::number(males.size()) + " Male");
    else
        ui->listStats->addItem(QString::number(males.size()) + " Males");

    if(females.size() == 1)
        ui->listStats->addItem(QString::number(females.size()) + " Female");
    else
        ui->listStats->addItem(QString::number(females.size()) + " Females");

    ui->listStats->addItem(QString::number(alive.size()) + " Alive");
    ui->listStats->addItem(QString::number(dead) + " Dead");

    if(computers.size() == 1)
        ui->listStats->addItem(QString::number(computers.size()) + " Computer");
    else
        ui->listStats->addItem(QString::number(computers.size()) + " Computers");

    if(totalConnections == 1)
        ui->listStats->addItem(QString::number(totalConnections) + " Connection");
    else
        ui->listStats->addItem(QString::number(totalConnections) + " Connections");
}

void MainWindow::displayClock()
{
    QTime time = QTime::currentTime();
    QString timeText = time.toString("hh : mm : ss");
    ui->digitalClock->setText(timeText);
}


void MainWindow::on_toolButton_clicked()
{
    MusicDialog musicDialog(this);
    musicDialog.exec();
}
