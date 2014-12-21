#include "xmppclient.h"

xmppClient::xmppClient(MonitorScreen* ms, RosterScreen* rs, QObject *parent)
    : QXmppClient(parent)
{
    this->ms = ms;
    this->rs = rs;
    connect(this, SIGNAL(connected()), SLOT(clientConnected()));
    connect(&this->rosterManager(), SIGNAL(rosterReceived()), SLOT(rosterReceived()));
    connect(&this->rosterManager(), SIGNAL(presenceChanged(QString,QString)), SLOT(presenceChanged(QString,QString)));
}

void xmppClient::clientConnected()
{
    qDebug("CONNECTED");
}

void xmppClient::rosterReceived()
{
    foreach (const QString &bareJid, rosterManager().getRosterBareJids()) {
        QString name = rosterManager().getRosterEntry(bareJid).name();
        if(name.isEmpty())
            name = "-";
        this->rs->addUser(bareJid, name);
    }
}

void xmppClient::presenceChanged(const QString& bareJid, const QString& resource)
{
    QDateTime current = QDateTime::currentDateTime();
    qDebug(qPrintable(current.toString()));
    qDebug("Presence changed %s/%s", qPrintable(bareJid), qPrintable(resource));
    QSettings settings;
    QString monitorList = settings.value("facebook/monitor").toString();
    QStringList monitor = monitorList.split(",");
    QStringList list;
    for (int i = 0; i < monitor.size(); i++) {
        if (!monitor.at(i).contains("|")) {
            QStringList splitName = monitor.at(i).split("|");
            QString userID = splitName.at(0);
            if (userID.compare(bareJid) == 0) {

            }
        }
    }
}
