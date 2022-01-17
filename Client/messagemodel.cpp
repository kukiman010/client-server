#include "messagemodel.h"


int MessageModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;

    return mList->items().size();
}

QVariant MessageModel::data(const QModelIndex &index, int role) const
{
    const Message item = mList->items().at(index.row());
    switch (role) {
    case text:
        return QVariant(item._text);
    case userName:
        return QVariant(item._userName);
    case date_send:
        return  QVariant(item._date_send);
    case date_server:
        return  QVariant(item._date_server);
    case date_read:
        return  QVariant(item._date_read);
    }

    return QVariant();
}

bool MessageModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    Message item = mList->items().at(index.row());
    switch (role) {
    case text:
        item._text = value.toString();
        break;
    case userName:
        item._userName = value.toString();
        break;
    case date_send:
        item._date_send = value.toInt();
        break;
    case date_server:
        item._date_send = value.toInt();
        break;
    case date_read:
        item._date_read = value.toInt();
        break;
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags MessageModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> MessageModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[text]         = "text";
    names[userName]     = "userName";
    names[date_send]    = "date_send";
    names[date_server]  = "date_server";
    names[date_read]    = "date_read";
    return names;
}

void MessageModel::setList(MessageList *list)
{
    beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

//    if (mList) {
//        connect(mList, MessageList::preItemAppended, this, [=]() {
//            const int index = mList->items().size();
//            beginInsertRows(QModelIndex(), index, index);
//        });
//        connect(mList, &MessageList::postItemAppended, this, [=]() {
//            endInsertRows();
//        });

//        connect(mList, &MessageList::preItemRemoved, this, [=](int index) {
//            beginRemoveRows(QModelIndex(), index, index);
//        });
//        connect(mList, &MessageList::postItemRemoved, this, [=]() {
//            endRemoveRows();
//        });
//    }

    endResetModel();
}
