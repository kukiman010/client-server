#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H
#include <QAbstractListModel>
#include "messagelistl.h"

class MessageModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(MessageList *list READ list WRITE setList)
    MessageList * mList;

public:
    MessageModel(QObject *parent = nullptr): QAbstractListModel(parent) , mList(nullptr) {}

    enum {
        text = Qt::UserRole,
        userName,
        date_send,
        date_server,
        date_read
    };

    // Basic functionality:
    int                                 rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant                            data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    // Editable:
    bool                                setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags                       flags(const QModelIndex& index) const override;
    virtual QHash<int, QByteArray>      roleNames() const override;
    MessageList *                       list() const {return mList;}
    void                                setList(MessageList *list);
};

#endif // MESSAGEMODEL_H
