#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>

#include "monitorscreen.h"
#include "rosterscreen.h"
#include "settingsscreen.h"

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
signals:

public slots:

};

#endif // MAINSCREEN_H
