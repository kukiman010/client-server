#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include "command.h"
#include "user.h"
#include "storageapi.h"

class Handler: public QObject
{
    Q_OBJECT

    StorageApi storage;

public slots:
//    void new_connect(Cmd ptr){}

public:
    explicit Handler(QObject *parent = nullptr);
    ~Handler(){}


    void to_process(Cmd com);

signals:
    void to_send(Cmd);
//    void  disconnect(Cmd ptr){}
    void create(User*);
};

#endif // HANDLER_H
