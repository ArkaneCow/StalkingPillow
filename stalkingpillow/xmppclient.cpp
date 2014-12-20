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
    qDebug("Roster received");
    foreach (const QString &bareJid, rosterManager().getRosterBareJids()) {
        QString name = rosterManager().getRosterEntry(bareJid).name();
        if(name.isEmpty())
            name = "-";
        qDebug("%s [%s]", qPrintable(bareJid), qPrintable(name));
        this->rs->addUser(name);
    }
}

void xmppClient::presenceChanged(const QString& bareJid, const QString& resource)
{
    QDateTime current = QDateTime::currentDateTime();
    qDebug(qPrintable(current.toString()));
    qDebug("Presence changed %s/%s", qPrintable(bareJid), qPrintable(resource));
}
