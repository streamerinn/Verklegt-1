#include "viewcomputers.h"
#include "ui_viewcomputers.h"

viewComputers::viewComputers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewComputers)
{
    ui->setupUi(this);
}

viewComputers::~viewComputers()
{
    delete ui;
}
