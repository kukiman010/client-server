#include "messagelistl.h"

bool MessageList::setItemAt(int index, const Message &item)
{
    if (index < 0 || index >= _vec.size())
        return false;

    const Message &oldItem = _vec.at(index);
    if (item._text == oldItem._text && item._userName == oldItem._userName && item._date_send == oldItem._date_send)
        return false;

    _vec[index] = item;
    return true;
}
