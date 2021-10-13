#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "gamelogic.h"
#include "socket.h"

#include <QPrinter>
#include <QPainter>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);


    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    Socket soc;
//    soc.sing_in("qwerty", "1234");


    return app.exec();
}
