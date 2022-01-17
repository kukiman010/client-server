#include <QQmlApplicationEngine>
//#include <QGuiApplication>
#include <QApplication>
#include <QQmlContext>

//#include "gamelogic.h"
#include "socket.h"
#include "gui_core.h"

#include <messagelistl.h>
#include <messagemodel.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qmlRegisterType<MessageModel>("Message", 1, 0, "MessageModel");
    qmlRegisterUncreatableType<MessageList>("Message", 1, 0, "MessageList",
        QStringLiteral("MessageList should not be created in QML"));
//    qmlRegisterType<MyWidget>("gui", 1, 0, "gui");

    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    GuiCore gui;
    MessageList messageList;



    QQmlContext * context = engine.rootContext();
    context->setContextProperty("gui", &gui);
    engine.rootContext()->setContextProperty(QStringLiteral("messageList"), &messageList);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

//    if(gui.save_main_menu)
//        emit gui.send_def_sett(gui.save_main_menu, gui.def_user, gui.def_pass);


    return app.exec();
}
