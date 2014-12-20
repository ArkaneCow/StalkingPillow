#ifndef ROSTERSCREEN_H
#define ROSTERSCREEN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include <QMap>

class RosterScreen : public QWidget
{
    Q_OBJECT
public:
    explicit RosterScreen(QWidget *parent = 0);
    void addUser(QString userID);
    void removeUser(QString userID);
private:
    QVBoxLayout* mainLayout;
    QVBoxLayout* layout;
    QScrollArea* scroll;
    QMap<QString, QPushButton*> pointerMap;
signals:

public slots:
};

#endif // ROSTERSCREEN_H
