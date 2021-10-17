#include <QQmlApplicationEngine>
//#include <QGuiApplication>
#include <QApplication>
#include <QQmlContext>

//#include "gamelogic.h"
#include "socket.h"
#include "gui_core.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    GuiCore gui;

//    qmlRegisterType<MyWidget>("gui", 1, 0, "gui");

    QQmlContext * context = engine.rootContext();
    context->setContextProperty("gui", &gui);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

//    if(gui.save_main_menu)
//        emit gui.send_def_sett(gui.save_main_menu, gui.def_user, gui.def_pass);


    return app.exec();
}
