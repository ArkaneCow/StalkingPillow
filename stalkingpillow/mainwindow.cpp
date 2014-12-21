#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->main = new MainScreen(this);
    this->setCentralWidget(this->main);
}
