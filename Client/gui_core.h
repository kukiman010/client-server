#ifndef GUICORE_H
#define GUICORE_H

#include <QObject>
#include <QAbstractListModel>
#include "socket.h"

class GuiCore : public QObject
{
    Q_OBJECT

    Socket * soc;

signals:
//    void to_gui(uint count);
    void to_authorization(bool auth);


public slots:
//    void from_gui();
    void authorization(QString name, QString pass);
    void from_auth(bool answer);

public:
    GuiCore(QObject *parent = nullptr);
    ~GuiCore(){}

//    Q_INVOKABLE void from_gui();

};

#endif // GUICORE_H
