#include "socket.h"


Socket::Socket(QObject *parent) : QObject(parent)
{
    qDebug() << "Client\n";
    _socket.connectToHost(QHostAddress("127.0.0.1"), 4242);
    connect(&_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()) );

    _id_client =0;
}

Socket::~Socket()
{

}

void Socket::onReadyRead()
{
    QByteArray arr = _socket.readAll();

    Cmd cmd = Cmd(new Command);
    QDataStream stream(&arr, QIODevice::ReadOnly);
    stream >> *cmd;

    if(cmd == nullptr)
        return;
    else
        loop(cmd);

}


void Socket::send(Cmd com)
{
    com.data()->setId(_id_client != 0 ? _id_client : 0);
    QByteArray bytes;
    QDataStream stream1(&bytes, QIODevice::WriteOnly);
    stream1 << *com;

    _socket.write(bytes);
}

void Socket::sing_in(const QString user, const QString pass)
{
    Cmd ptr = Cmd(new Command);


    ptr->setAction(Command::CA_sing_in);
    ptr->setType(Command::CT_system);
    ptr->setRevers(Command::CR_status_connect);
//    ptr->setUser("");

    Command::simpleObject obj, obj1,obj2;
    obj.com_SO = Command::CSO_login;
    ptr->setInfo(obj);

    obj1.com_SO = Command::CSO_user;
    obj1.object = user;
    ptr->addObject(obj1);

    obj2.com_SO = Command::CSO_pass;
    obj2.object = pass;
    ptr->addObject(obj2);


    send(ptr);
}

void Socket::loop(Cmd com)
{
//    Cmd ptr = Cmd(new Command);


    if(com->getType() == Command::CT_storage)
    {

    }
    else if(com->getType() == Command::CT_users)
    {

    }
    else if(com->getType() == Command::CT_system)
    {
        if(com->getAction() == Command::CA_connect &&
                com.data()->getRevers() == Command::CR_status_connect)
        {
            sing_in("qwerty", "123");
        }
        else if(com.data()->getAction() == Command::CA_client_id &&
                com.data()->getRevers() == Command::CR_status_connect)
        {
            _id_client = com.data()->getId();
            sing_in("qwerty", "1234");
        }

    }
    else if(com.data()->getType() == Command::CT_error)
    {

    }
    else
    {
        QTime time = QDateTime::currentDateTime().time();
        qDebug() << time.hour()<< ":" << time.minute() <<":"
                 << time.second() << "  Unknown team";
    }

}
