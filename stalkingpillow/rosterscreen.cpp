#include "rosterscreen.h"

RosterScreen::RosterScreen(QWidget *parent) :
    QWidget(parent)
{
    this->mainLayout = new QVBoxLayout(this);
    this->scroll = new QScrollArea();
    this->mainLayout->addWidget(this->scroll);
    QWidget* contents = new QWidget();
    this->layout = new QVBoxLayout(contents);
    this->layout->setSizeConstraint(QLayout::SetMinimumSize);
    this->scroll->setWidget(contents);
    this->signalMap = new QSignalMapper(this);
}
void RosterScreen::addUser(QString userID, QString userName) {
    bool contains = this->pointerMap.contains(userID);
    if (!contains) {
        QPushButton* b = new QPushButton();
        b->setText(userName);
        connect(b, SIGNAL(clicked()), this->signalMap, SLOT(map()));
        QString userData = userID + "|" + userName;
        this->signalMap->setMapping(b, userData);
        connect(this->signalMap, SIGNAL(mapped(QString)), this, SLOT(monitorUser(QString)));
        this->layout->addWidget(b);
        this->pointerMap.insert(userID, b);
        this->jabberMap.insert(userID, userName);
        for (int i = 0; i < this->layout->count(); i++) {
            QWidget* w = this->layout->itemAt(i)->widget();
            w->setMinimumWidth(this->parentWidget()->width());
        }
    }
}
void RosterScreen::removeUser(QString userID) {
    bool contains = this->pointerMap.contains(userID);
    if (contains) {
        QPushButton* p = (QPushButton*) this->pointerMap.value(userID);
        this->signalMap->removeMappings(p);
        p->disconnect();
        this->layout->removeWidget(p);
        delete p;
        this->pointerMap.remove(userID);
        this->jabberMap.remove(userID);
        for (int i = 0; i < this->layout->count(); i++) {
            QWidget* w = this->layout->itemAt(i)->widget();
            w->setMinimumWidth(this->parentWidget()->width());
        }
    }
}
void RosterScreen::monitorUser(QString userData) {
    QSettings settings;
    QString old = "";
    if (settings.contains("facebook/monitor")) {
        old += settings.value("facebook/monitor").toString();
    }
    QStringList data = old.split(",");
    if (!data.contains(userData)) {
        QString newList = old + userData + ",";
        settings.setValue("facebook/monitor", newList);
    }
}
