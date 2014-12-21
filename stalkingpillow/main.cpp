#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setOrganizationName("PillowSoft");
    QApplication::setApplicationName("PillowStalk");
    MainWindow mw;
    mw.show();
    return a.exec();
}
