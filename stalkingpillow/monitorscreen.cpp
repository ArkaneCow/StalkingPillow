#include "monitorscreen.h"

MonitorScreen::MonitorScreen(QWidget *parent) :
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
    QSettings settings;
    QString monitorList = settings.value("facebook/monitor").toString();
    QStringList data = monitorList.split(",");
    for (int i = 0; i < data.size(); i++) {
        if (data.at(i).contains("|")) {
            QStringList userData = data.at(i).split("|");
            QString userID = userData.at(0);
            QString userName = userData.at(1);
            this->addUser(userID, userName);
        }
    }
}
void MonitorScreen::addUser(QString userID, QString userName) {
    bool contains = this->pointerMap.contains(userID);
    if (!contains) {
        QPushButton* b = new QPushButton();
        b->setText(userName);
        connect(b, SIGNAL(clicked()), this->signalMap, SLOT(map()));
        QString userData = userID + "|" + userName;
        this->signalMap->setMapping(b, userData);
        connect(this->signalMap, SIGNAL(mapped(QString)), this, SLOT(unmonitorUser(QString)));
        this->layout->addWidget(b);
        this->pointerMap.insert(userID, b);
        this->jabberMap.insert(userID, userName);
        for (int i = 0; i < this->layout->count(); i++) {
            QWidget* w = this->layout->itemAt(i)->widget();
            w->setMinimumWidth(this->parentWidget()->width());
        }
    }
}
void MonitorScreen::removeUser(QString userID) {
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
void MonitorScreen::unmonitorUser(QString userData) {
    QSettings settings;
    QString old = "";
    if (settings.contains("facebook/monitor")) {
        old += settings.value("facebook/monitor").toString();
    }
    QStringList userDataSplit = userData.split("|");
    QString userID = userDataSplit.at(0);
    QStringList data = old.split(",");
    if (data.contains(userData)) {
        QString newData = "";
        for (int i = 0; i < data.size(); i++) {
            if (!data.at(i).compare(userData) == 0) {
                newData += data.at(i);
                newData += ",";
            }
        }
        settings.setValue("facebook/monitor", newData);
        this->removeUser(userID);
    }
}
