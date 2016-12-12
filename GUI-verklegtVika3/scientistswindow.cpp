#include "scientistswindow.h"
#include "ui_scientistswindow.h"

scientistsWindow::scientistsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scientistsWindow)
{
    ui->setupUi(this);
}

scientistsWindow::~scientistsWindow()
{
    delete ui;
}
