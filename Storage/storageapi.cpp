#include "storageapi.h"

StorageApi::StorageApi()
{

}

bool StorageApi::findUser(QString login, QString pass)
{
    if(login == "qwerty" && pass == "123")
        return true;


    return false;
}
