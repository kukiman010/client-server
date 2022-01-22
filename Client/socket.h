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

    void loop(Cmd com);

signals:
    void gui_authorization(bool aut);

public:
    explicit Socket(QObject *parent = nullptr);
    ~Socket();

    void                sing_in(const QString user = "", const QString pass = "");
    QString             getUserName()   {return _userClient;}
    uint                getId()         {return _idClient;}


public slots:
    void onReadyRead();
    void send(Cmd com);

private:
    QTcpSocket      _socket;
    QString         _userClient;
    uint            _idClient;


};


#endif // SOCKET_H
