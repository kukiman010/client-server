#include "socket.h"


Socket::Socket(QObject *parent) : QObject(parent)
{
    qDebug() << "Server\n";
    hand = new Handler();
    _soc_id = 0;

    connect(hand, SIGNAL(to_send(Cmd)) , this, SLOT(send(Cmd)) );
//    connect(hand, SIGNAL(create(User*) ), this, SLOT(create_user(User*)));

    _server.listen(QHostAddress::Any, 4242);
    connect(&_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

void Socket::onNewConnection()
{
    QTcpSocket *clientSocket = _server.nextPendingConnection();

    Cmd ptr = Cmd(new Command);
    ptr->setType(Command::CT_system);
    ptr->setAction(Command::CA_client_id);
    ptr->setRevers(Command::CR_status_connect);
    ptr->setId( push_sockets(clientSocket) );


    connect(clientSocket , SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

    send(ptr);
}

void Socket::onSocketStateChanged(QAbstractSocket::SocketState socketState)//disconect
{
//    if (socketState == QAbstractSocket::UnconnectedState)
//    {
//        QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());

//        std::map<uint, QTcpSocket*>::iterator it = _sockets.begin();

//        for(; it != _sockets.end(); ++it)
//        {
//            if(it->second == sender)
//            {
//                _sockets.erase(it);

//                qDebug() << "disconect "<< sender;
//                disconnect(sender, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
//                disconnect(sender , SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));
//                delete  sender;

//                break;
//            }
//            qDebug() << "find!";
//        }
//    }
}

void Socket::onReadyRead()
{
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    QByteArray arr = sender->readAll();

    Cmd cmd = Cmd(new Command);
    QDataStream stream2(&arr, QIODevice::ReadOnly);
    stream2 >> *cmd;

    hand->to_process(cmd);
}

void Socket::send(Cmd com)
{
    QByteArray arr;
    QDataStream stream(&arr, QIODevice::WriteOnly);
    stream << *com;

    std::map<uint, QTcpSocket*>::iterator it = _sockets.find(com.data()->getId());
    if(it == _sockets.end())
    {
        QTime time = QDateTime::currentDateTime().time();
        qDebug() << QString::number(time.hour()) + ":" + QString::number(time.minute()) + ":" + QString::number(time.second()) << " Dont faun user";
    }
    else
        it->second->write(arr);
}

void Socket::create_user(User* user)
{
//    std::map<QString, User*>::iterator it = _sockets.find(user->get_name());

//    if(it == _sockets.end())
//        _sockets.insert(std::pair<QString, User*>(user->get_name(), user));
//    else
        qDebug() << "Such user already exists" << user->get_name();
}

uint Socket::push_sockets(QTcpSocket *tcp)
{
    _mutex.lock();
    uint cache =0;
    _soc_id++;

    std::map<uint, QTcpSocket*>::iterator it = _sockets.find(_soc_id);
    if(it == _sockets.end())
    {
        cache = _soc_id;
        _sockets.emplace(_soc_id, tcp);
    }
    _mutex.unlock();

    return cache;
}







