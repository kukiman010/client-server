#ifndef USER_H
#define USER_H

#include <QTcpSocket>

#include <command.h>

class User
{

    QTcpSocket* _socket;
    QString _name;



public:
    User(QTcpSocket* soc)
    {
        _UserStatus = US_init;
        _name = "none";
        _socket =  soc;
    }
    ~User() {delete _socket;}

    enum User_Status
    {
        US_null = 0,
        US_init,
        US_actual,
        US_invalid,
        US_
    }_UserStatus;

    User_Status                 get_status()                    {return _UserStatus;}
    void                        set_status(User_Status us)      {_UserStatus = us;}

    QTcpSocket *                get_socket()                    {return _socket;}

    QString                     get_name()                      {return _name;}
    void                        set_name(QString name)          {_name = name;}

    User &  operator=(const User & other)
    {
        if (this == & other)
            return * this;

        this->_UserStatus = other._UserStatus;
        this->_name = other._name;
        this->_socket = other._socket;

        return * this;
    }

};

#endif // USER_H
