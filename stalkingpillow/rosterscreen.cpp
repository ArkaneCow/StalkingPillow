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
}
void RosterScreen::addUser(QString userID) {
    bool contains = this->pointerMap.contains(userID);
    if (!contains) {
        QPushButton* b = new QPushButton();
        b->setText(userID);
        this->layout->addWidget(b);
        this->pointerMap.insert(userID, b);
    }
}
void RosterScreen::removeUser(QString userID) {
    bool contains = this->pointerMap.contains(userID);
    if (contains) {
        QPushButton* p = (QPushButton*) this->pointerMap.value(userID);
        this->layout->removeWidget(p);
        delete p;
        this->pointerMap.remove(userID);
    }
}
