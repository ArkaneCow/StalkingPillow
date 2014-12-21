#ifndef ROSTERSCREEN_H
#define ROSTERSCREEN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QMap>
#include <QSettings>
#include <QSignalMapper>

#include "monitorscreen.h"

class RosterScreen : public QWidget
{
    Q_OBJECT
public:
    explicit RosterScreen(MonitorScreen* ms, QWidget *parent = 0);
    void addUser(QString userID, QString userName);
    void removeUser(QString userID);
private:
    QVBoxLayout* mainLayout;
    QVBoxLayout* layout;
    QScrollArea* scroll;
    QMap<QString, QPushButton*> pointerMap;
    QMap<QString, QString> jabberMap;
    QSignalMapper* signalMap;

    MonitorScreen* ms;
signals:

public slots:
    void monitorUser(QString userData);
};

#endif // ROSTERSCREEN_H
