#include "storageapi.h"

StorageApi::StorageApi()
{

}

bool StorageApi::findUser(QString login, QString pass)
{
    if(login == "qwerty" && pass == "1234")
        return true;
    else if(login == "qwerty1" && pass == "1234")
        return true;
    else if(login == "qwerty2" && pass == "1234")
        return true;


    return false;
}
