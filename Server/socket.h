#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include <QDebug>
#include <QHostAddress>
#include <QAbstractSocket>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDateTime>
#include <map>


#include "command.h"
#include "handler.h"
#include "user.h"


class Socket : public QObject
{
    Q_OBJECT

public:
    explicit Socket(QObject *parent = nullptr);
    ~Socket();

public slots:
    void onNewConnection();
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);
    void onReadyRead();
    void send(Cmd com);
    void create_user(User);


private:
    QTcpServer  _server;
    std::map<QString, User> _sockets;

    Handler * hand;
};



#endif // SOCKET_H
