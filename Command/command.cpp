#include "command.h"

//Command::Command()
//{
////    qRegisterMetaType< Cmd >( "Cmd" );
//}


QDataStream & operator >>(QDataStream &stream, Command &command)
{
    uint8_t act, rev, typ;
    uint size;
    QString str;

    stream  >> act
            >> rev
            >> typ
            >> command._user
            >> command._info
            >> size;

    for(uint i=0;i < size; ++i)
    {
        Command::simpleObject obj;
        stream >> obj;
        command._objects.push_back(obj);
    }
    command._action = static_cast<Command::commandAction>(act);
    command._revers = static_cast<Command::commandRevers>(rev);
    command._type = static_cast<Command::commandType>(typ);

    return stream;
}

QDataStream & operator <<(QDataStream &stream, Command &command)
{
    stream  << static_cast<uint8_t>(command._action)
            << static_cast<uint8_t>(command._revers)
            << static_cast<uint8_t>(command._type)
            << command._user
            << command._info
            << static_cast<uint>( command._objects.size() );

    for(auto i: command._objects)
        stream << i;

    return stream;
}


QDataStream & operator >>(QDataStream &stream, Command::simpleObject &sObj)
{
    uint8_t CSO,CR;
    stream  >> CSO
            >> CR
            >> sObj.object;
    sObj.com_SO = static_cast<Command::commandSObj>(CSO);
    sObj.com_R = static_cast<Command::commandRevers>(CR);

    return stream;
}

QDataStream & operator <<(QDataStream &stream, Command::simpleObject &sObj)
{
    stream  << static_cast<uint8_t>(sObj.com_SO)
            << static_cast<uint8_t>(sObj.com_R)
            << sObj.object;

    return stream;
}
