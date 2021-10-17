#include "gui_core.h"

//void GuiCore::from_gui()
//{
//    ++counter;
//    emit to_gui(counter);
//}

void GuiCore::authorization(QString name, QString pass)
{
    soc->sing_in(name, pass);
}

void GuiCore::from_auth(bool answer)
{
    emit to_authorization(answer);
}

GuiCore::GuiCore(QObject *parent) : QObject(parent)
{
    soc = new Socket();
    connect(soc, SIGNAL(gui_authorization(bool)), this, SLOT(from_auth(bool)));

}



