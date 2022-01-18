import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0

import Message 1.0

Page
{
    id: root
    anchors.fill: parent
//    property string username: "not find"
//    property string username: left_bar.width + " " + left_bar.height
    property string username: chat.height

    Rectangle
    {
        id: top_bar
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        height: 50
        width: root.width
        color: "green"

        Text {
            id: userLabel
            anchors.verticalCenter: parent.verticalCenter
            x: 25
            text: username
            font.pixelSize: 14
        }
        Button
        {
            id: but_logOff
            anchors.verticalCenter: parent.verticalCenter
            x: parent.width - 25 - width
            text: "Выйти"

        }
    }

    Rectangle
    {
        id: left_bar
        color: "red"
        anchors.left: root.left
        width: ( (root.width / 3 ) * 2) - 10
        height: root.height - top_bar.height - 10

        x: 5
        y: top_bar.height + 5
    }

    Rectangle
    {
        id: chat
        color: "black"
        width: (root.width / 3 ) - 10
        height: root.height - top_bar.height - 10
        x: left_bar.width + 10
        y: top_bar.height + 5
        ColumnLayout
        {
            anchors.fill: parent

            Frame
            {
                Layout.fillWidth: true

                ListView
                {
                    anchors.fill: parent
                    implicitWidth: chat.width
                    implicitHeight: chat.height

                    clip: true

                    model: MessageModel
                    {
                        list: messageList
                    }

                    delegate: RowLayout
                    {
                        width: parent.width
//                        height: parent.height

                        TextField
                        {
                            text: model.text
                            onEditingFinished: model.text = text
                            Layout.fillWidth: true
                        }
                        TextField
                        {
                            text: model.userName
                            onEditingFinished: model.userName = text
                            Layout.fillWidth: true
                        }

                    }
                }
            }

    //        RowLayout
    //        {
    //            Button
    //            {
    //                text: qsTr("Add new item")
    //                onClicked: toDoList.appendItem()
    //                Layout.fillWidth: true
    //            }
    //            Button
    //            {
    //                text: qsTr("Remove completed")
    //                onClicked: toDoList.removeCompletedItems()
    //                Layout.fillWidth: true
    //            }
    //        }
        }


        Row {
            id: row
            height: 50
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            spacing: 5

            TextField
            {
                id: text_mess
                placeholderText: qsTr("Enter message")
                text: ""
                width: row.width - button1.width - 5
                height: 50
            }

            Button
            {
                id: button1
                Text
                {
                    anchors.centerIn: parent
                    id: te1
                    text: "send"
                }
                width: te1.width + (te1.width * 0.9)
                height: 50

//                onClicked: {
//                    if(text_mess.text !== "")
//                    {
//                        listModel.append({idshnik:  user_name + ": " + text_mess.text})
//                        ++number
//                    }
//                }
            }


        }

    }
}




