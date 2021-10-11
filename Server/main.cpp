#include <QCoreApplication>
#include "socket.h"
#include <QByteArray>

//#include "saved_container.h"
#include "user.h"

#include <QtDebug>
#include <QTextStream>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Socket socket;



//    QTcpSocket * soc = new QTcpSocket();
//    User us(soc);
//    socket.create_user(us);

    //    std::vector<User> vec;
//    std::map<QString, User> m;

//    vec.push_back(us);
//    m.emplace(us.get_name(), us);

//    qDebug() << " " << vec.size();


    return a.exec();
}
