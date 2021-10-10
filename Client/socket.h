#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QHostAddress>
#include <iostream>
#include <QDateTime>
#include "command.h"

class Socket : public QObject
{
    Q_OBJECT

public:
    explicit Socket(QObject *parent = nullptr);
    ~Socket();

    void sing_in(const QString user = "", const QString pass = "");


public slots:
    void onReadyRead();
    void send(Cmd com);

private:
    QTcpSocket  _socket;
    QString userClient;


};


#endif // SOCKET_H
