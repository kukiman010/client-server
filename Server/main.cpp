#include <QCoreApplication>
#include <QByteArray>
#include <QFileInfo>


#include "socket.h"
//#include "saved_container.h"
#include "user.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Socket socket;


    return a.exec();
}
