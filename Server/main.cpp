#include <QCoreApplication>
#include "socket.h"
#include <QByteArray>

#include "saved_container.h"

#include <QtDebug>
//#include <QPrinter>
//#include <QPainter>
#include <QTextStream>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    Cmd com = Cmd(new Command);
//    com->setAction(Command::CA_connect);
//    com->setType(Command::CT_system);
//    com->setRevers(Command::CR_status_connect);
//    com->setUser("kukiman");

//    Command::simpleObject obj, obj1,obj2;
//    obj.com_SO = Command::CSO_login;

//    com->setInfo(obj);

//    obj1.com_SO = Command::CSO_user;
//    obj1.object = "kukiman";
//    com->addObject(obj1);

//    obj2.com_SO = Command::CSO_pass;
//    obj2.object = "1234";
//    com->addObject(obj2);

//    QByteArray bytes1;
//    QDataStream stream1(&bytes1, QIODevice::WriteOnly);
//    stream1 << *com;



//    QByteArray bytes2;
//    bytes2 = bytes1;

//    Cmd com2 = Cmd(new Command);
//    QDataStream stream2(&bytes2, QIODevice::ReadOnly);
//    stream2 >> *com2;

    Socket soc;/////////////////////////////////////////////////
//    SQueue<int> t;


//    QPrinter printer(QPrinter::HighResolution); //create your QPrinter (don't need to be high resolution, anyway)
//    printer.setPageSize(QPrinter::A4);
//    printer.setOrientation(QPrinter::Portrait);
//    printer.setPageMargins (15,15,15,15,QPrinter::Millimeter);
//    printer.setFullPage(false);
//    printer.setOutputFileName("output.pdf");
//    printer.setOutputFormat(QPrinter::PdfFormat); //you can use native format of system usin QPrinter::NativeFormat

//    QPainter painter(&printer); // create a painter which will paint 'on printer'.
//    painter.setFont(QFont("Tahoma",8));
//    painter.drawText(200,200,"Test");
//    painter.end();

/////////////////////////////////////////////////////////////////////
//    QTextStream out (stdout);
//    if(argc != 2)
//    {
//        qWarning("Usage : file_size file");
//        return 1;
//    }
//    QString filename = argv[1];
//    if (!QFile(filename).exists())
//    {
//        qWarning("The file does not exist");
//        return 1;
//    }
//    QFileInfo fileinfo(filename);
//    qint64 size = fileinfo.size();
//    QString str= "The file size is : %1 bytes";
//    out << str.arg(size)<<"\n";

//    qDebug() <<"end";

    return a.exec();
}
