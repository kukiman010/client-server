 #include "socket.h"



Socket::Socket(QObject *parent) : QObject(parent)
{
   qDebug() << "Server\n";
   hand = new Handler();

   connect(hand, SIGNAL(to_send(Cmd)) , this, SLOT(send(Cmd)) );
   connect(hand, SIGNAL(create(User) ), this, SLOT(create_user(User)));

   _server.listen(QHostAddress::Any, 4242);
   connect(&_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

Socket::~Socket()
{

}

void Socket::onNewConnection()
{
    QTcpSocket *clientSocket = _server.nextPendingConnection();


    connect(clientSocket , SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

void Socket::onSocketStateChanged(QAbstractSocket::SocketState socketState)//disconect
{
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
        
        std::map<QString, User>::iterator it = _sockets.begin();
        
        for(; it != _sockets.end(); ++it)
        {
            if(it->second.get_socket() == sender)
            {
                _sockets.erase(it);
                
                qDebug() << "disconect "<< sender;
                disconnect(sender, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
                disconnect(sender , SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));
                delete  sender;
                
                break;
            }
            qDebug() << "find!";
        }
    }
}

void Socket::onReadyRead()
{
   QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
   QByteArray arr = sender->readAll();

   Cmd cmd = Cmd(new Command);
   QDataStream stream2(&arr, QIODevice::ReadOnly);
   stream2 >> *cmd;


   hand->to_process(cmd, sender);
}

void Socket::send(Cmd com)
{
    QByteArray arr;
    QDataStream stream(&arr, QIODevice::WriteOnly);
    stream << *com;

//    std::map<QString, User>::iterator it = _sockets.begin();
//    it->second.get_socket()->write(arr);


//   QTime time = QDateTime::currentDateTime().time();
    //       str = QString::number(time.hour()) + ":" + QString::number(time.minute()) + ":" + QString::number(time.second());
}

void Socket::create_user(User user)
{
    std::map<QString, User>::iterator it = _sockets.find(user.get_name());
//    if(it == _sockets.end())
//        _sockets.emplace( user.get_name(), user);
//    else
//        qDebug() << "Such user already exists" << user.get_name();
}












