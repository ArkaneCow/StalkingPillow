#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>

#include "monitorscreen.h"
#include "rosterscreen.h"
#include "settingsscreen.h"
#include "xmppclient.h"

class MainScreen : public QWidget
{
    Q_OBJECT
public:
    explicit MainScreen(QWidget *parent = 0);
private:
    QTabWidget* tabs;
    QVBoxLayout* layout;

    MonitorScreen* ms;
    RosterScreen* rs;
    SettingsScreen* ss;
    xmppClient* xmpp;
signals:

public slots:

};

#endif // MAINSCREEN_H
