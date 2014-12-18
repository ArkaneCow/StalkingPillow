#include "mainscreen.h"

MainScreen::MainScreen(QWidget *parent) :
    QWidget(parent)
{   
#ifdef Q_OS_ANDROID || Q_OS_IOS
    this->setWindowState(Qt::WindowMaximized);
#endif
    this->layout = new QVBoxLayout();
    this->ms = new MonitorScreen();
    this->rs = new RosterScreen();
    this->ss = new SettingsScreen();
    this->tabs = new QTabWidget();
    this->layout->addWidget(this->tabs);
    this->tabs->addTab(this->ms, "Monitor");
    this->tabs->addTab(this->rs, "Roster");
    this->tabs->addTab(this->ss, "Settings");
    QSettings settings;
    if (!settings.contains("facebook/username") || !settings.contains("facebook/password")) {
        this->tabs->setCurrentIndex(this->tabs->indexOf(this->ss));
    }
    this->setLayout(this->layout);
}
