#ifndef XMPPCLIENT_H
#define XMPPCLIENT_H

#include <QXmppClient.h>
#include <QXmppMessage.h>
#include <QXmppRosterManager.h>

#include "monitorscreen.h"
#include "rosterscreen.h"
#include "notificationclient.h"

class xmppClient : public QXmppClient
{
    Q_OBJECT

public:
    xmppClient(MonitorScreen* ms, RosterScreen* rs, QObject *parent = 0);
private:
    MonitorScreen* ms;
    RosterScreen* rs;
    NotificationClient* nc;
public slots:
    void clientConnected();
    void rosterReceived();
    void presenceChanged(const QString& bareJid, const QString& resource);
};

#endif // XMPPCLIENT_H
