#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Overrides the normal cursor with a nyanCat cursor
    QCursor customCursor(QPixmap(":/images/pictures/nyan-cat.png"));
    a.setOverrideCursor(customCursor);

    return a.exec();
}
