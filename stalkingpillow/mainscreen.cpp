#include "mainscreen.h"

MainScreen::MainScreen(QWidget *parent) :
    QWidget(parent)
{
#ifdef Q_OS_ANDROID || Q_OS_IOS
    this->setWindowState(Qt::WindowMaximized);
#endif
    this->layout = new QVBoxLayout();
    this->ms = new MonitorScreen(this);
    this->rs = new RosterScreen(ms, this);
    this->xmpp = new xmppClient(this->ms, this->rs);
    this->ss = new SettingsScreen(this->xmpp, this);
    this->tabs = new QTabWidget();
    this->tabs->addTab(this->ms, "Monitor");
    this->tabs->addTab(this->rs, "Roster");
    this->tabs->addTab(this->ss, "Settings");
    this->layout->addWidget(this->tabs);
    QSettings settings;
    if (!settings.contains("facebook/username") || !settings.contains("facebook/password")) {
        this->tabs->setCurrentIndex(this->tabs->indexOf(this->ss));
    }
    this->xmpp->connectToServer(settings.value("facebook/username").toString(), settings.value("facebook/password").toString());
    this->setLayout(this->layout);
}
