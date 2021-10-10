#ifndef STORAGEAPI_H
#define STORAGEAPI_H

//#include <QSqlDatabase>

#include "command.h"

class StorageApi
{
//    enum

public:
    StorageApi();

    bool findUser(QString login, QString pass);
};

#endif // STORAGEAPI_H
