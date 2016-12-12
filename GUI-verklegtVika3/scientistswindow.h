#ifndef SCIENTISTSWINDOW_H
#define SCIENTISTSWINDOW_H

#include <QDialog>

namespace Ui {
class scientistsWindow;
}

class scientistsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit scientistsWindow(QWidget *parent = 0);
    ~scientistsWindow();

private:
    Ui::scientistsWindow *ui;
};

#endif // SCIENTISTSWINDOW_H
