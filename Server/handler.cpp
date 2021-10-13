#include "handler.h"



Handler::Handler(QObject *parent) : QObject(parent)
{

}

void Handler::to_process(Cmd com)
{
    QString user ="", pass="";
    if(com.data()->getType() == Command::commandType::CT_system &&
            com.data()->getAction() == Command::CA_sing_in)
    {
        for(auto i: com.data()->get_object())
        {
            if(Command::CSO_user == i.com_SO )
                user = i.object;
            else if(Command::CSO_pass == i.com_SO)
                pass = i.object;
        }

        bool status = storage.findUser(user,pass);

//        QTcpSocket * soc = new QTcpSocket(qts);

//        User* us =  new User(soc);
//        us->set_name(user);
//        if(status)
//            us->set_status(User::US_actual);
//        else
//            us->set_status(User::US_invalid);

        if(status)
        {
//            emit create(us);

            Cmd ptr = Cmd(new Command);
            ptr->setAction(Command::CA_connected);
            ptr->setType(Command::CT_system);
            ptr->setRevers(Command::CR_status_connect);
            ptr->setUser(user);
            ptr->setId(com->getId());

            emit to_send(ptr);
        }
        else
        {
            Cmd ptr = Cmd(new Command);
            ptr->setAction(Command::CA_sing_in);
            ptr->setType(Command::CT_error);
            ptr->setRevers(Command::CR_status_connect);
            ptr->setUser(user);
            ptr->setId(com->getId());

            emit to_send(ptr);
        }
    }


}










