#ifndef MASSAGEMODEL_H
#define MASSAGEMODEL_H

#include <QAbstractListModel>
#include <QtDebug>
#include <vector>

struct Message
{
    QString     _text;
    QString     _userName;
    int         _date_send;
    int         _date_server;
    int         _date_read;
};

class MessageList : public QObject
{
    Q_OBJECT

    std::vector<Message>  _vec;

public:
    MessageList() {
        _vec.push_back({QStringLiteral("test message"), QStringLiteral("user"),1,2,3});
        _vec.push_back({QStringLiteral("test message"), QStringLiteral("user"),1,2,3});
        _vec.push_back({QStringLiteral("test message"), QStringLiteral("user"),1,2,3});
        _vec.push_back({QStringLiteral("test message"), QStringLiteral("user"),1,2,3});
        _vec.push_back({QStringLiteral("test message"), QStringLiteral("user"),1,2,3});
        _vec.push_back({QStringLiteral("test message"), QStringLiteral("user"),1,2,3});
        _vec.push_back({QStringLiteral("test message"), QStringLiteral("user"),1,2,3});
        _vec.push_back({QStringLiteral("test message"), QStringLiteral("user"),1,2,3});
        _vec.push_back({QStringLiteral("test message"), QStringLiteral("user"),1,2,3});
        _vec.push_back({QStringLiteral("test message"), QStringLiteral("user"),1,2,3});
        _vec.push_back({QStringLiteral("test message"), QStringLiteral("user"),1,2,3});
    }

    void                        addMessage(Message note)        {_vec.push_back(note);}
    std::vector<Message>        items() const                   {return _vec;}

    bool                        setItemAt(int index, const Message &item);


};

#endif // MASSAGEMODEL_H
