#include <QApplication>
#include <QXmppClient.h>

#include "mainscreen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setOrganizationName("PillowSoft");
    QApplication::setApplicationName("PillowStalk");
    MainScreen ms;
    ms.show();
    return a.exec();
}
