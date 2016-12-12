#ifndef VIEWCOMPUTERS_H
#define VIEWCOMPUTERS_H

#include <QDialog>

namespace Ui {
class viewComputers;
}

class viewComputers : public QDialog
{
    Q_OBJECT

public:
    explicit viewComputers(QWidget *parent = 0);
    ~viewComputers();

private:
    Ui::viewComputers *ui;
};

#endif // VIEWCOMPUTERS_H
