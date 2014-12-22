#include "xmppclient.h"

xmppClient::xmppClient(MonitorScreen* ms, RosterScreen* rs, QObject *parent)
    : QXmppClient(parent)
{
    this->ms = ms;
    this->rs = rs;
    this->nc = new NotificationClient(this);
    connect(this, SIGNAL(connected()), SLOT(clientConnected()));
    connect(&this->rosterManager(), SIGNAL(rosterReceived()), SLOT(rosterReceived()));
    connect(&this->rosterManager(), SIGNAL(presenceChanged(QString,QString)), SLOT(presenceChanged(QString,QString)));
}

void xmppClient::clientConnected()
{
    this->nc->setNotification("new connected");
}

void xmppClient::rosterReceived()
{
    foreach (const QString &bareJid, rosterManager().getRosterBareJids()) {
        QString name = rosterManager().getRosterEntry(bareJid).name();
        if(name.isEmpty())
            name = "-";
        this->rs->addUser(bareJid, name);
    }
    QSettings settings;
    QString monitorList = settings.value("facebook/monitor").toString();
    QStringList monitor = monitorList.split(",");

    for (int i = 0; i < monitor.size(); i++) {
        if (monitor.at(i).contains("|")) {
            QStringList splitName = monitor.at(i).split("|");
            QString userID = splitName.at(0);
            QStringList res = rosterManager().getResources(userID);
            if (res.size() > 0) {
                QXmppPresence pre = rosterManager().getPresence(userID, rosterManager().getResources(userID).at(0));
                QPushButton* b = this->ms->pointerMap.value(userID);
                QString name = this->ms->jabberMap.value(userID);
                if (pre.type() == QXmppPresence::Chat || pre.type() == QXmppPresence::Online || pre.type() == QXmppPresence::Available) {
                    b->setText(name + " - " + "Online");
                } else {
                    b->setText(name + " - " + "Offline");
                }
            }
        }
    }
}

void xmppClient::presenceChanged(const QString& bareJid, const QString& resource)
{
    QSettings settings;
    QString monitorList = settings.value("facebook/monitor").toString();
    QStringList monitor = monitorList.split(",");

    for (int i = 0; i < monitor.size(); i++) {
        if (monitor.at(i).contains("|")) {
            QStringList splitName = monitor.at(i).split("|");
            QString userID = splitName.at(0);
            if (userID.compare(bareJid) == 0) {
                QMap<QString, QXmppPresence> presences = this->rosterManager().getAllPresencesForBareJid(bareJid);
                QXmppPresence& pre = presences[resource];
                QPushButton* b = this->ms->pointerMap.value(bareJid);
                QString name = this->ms->jabberMap.value(bareJid);
                if (pre.type() == QXmppPresence::Chat || pre.type() == QXmppPresence::Online || pre.type() == QXmppPresence::Available) {
                    b->setText(name + " - " + "Online");
                } else if (pre.type() == QXmppPresence::Away || pre.type() == QXmppPresence::Unavailable){
                    b->setText(name + " - " + "Offline");
                }
            }
        }
    }
}
