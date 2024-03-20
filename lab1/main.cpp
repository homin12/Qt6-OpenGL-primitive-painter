#include "mainwindow.h"

#include <QApplication>
#include "mainwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget wgt;
    wgt.show();
    return a.exec();
}
