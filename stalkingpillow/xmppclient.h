#ifndef XMPPCLIENT_H
#define XMPPCLIENT_H

#include "QXmppClient.h"
#include "QXmppMessage.h"
#include "QXmppRosterManager.h"

#include "monitorscreen.h"
#include "rosterscreen.h"

class xmppClient : public QXmppClient
{
    Q_OBJECT

public:
    xmppClient(QObject *parent = 0);

public slots:
    void clientConnected();
    void rosterReceived();
    void presenceChanged(const QString& bareJid, const QString& resource);
};

#endif // XMPPCLIENT_H
