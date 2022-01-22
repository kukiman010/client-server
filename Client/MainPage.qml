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
    property string username: (chat.width) + " " +(chat.height )
    property string message: text_mess.text
    signal buttonClicked();

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
        width: ( (root.width / 3 ) * 2) - 10
        height: root.height - top_bar.height - 10

        x: 5
        y: top_bar.height + 5
    }

    Rectangle
    {
        id: chat
//        color: "black"
        width: (root.width / 3 ) - 10
        height: (root.height - top_bar.height - 10) - row.height
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
                    implicitWidth: chat.width
                    implicitHeight: chat.height - (row.height/2)
                    anchors.fill: parent
                    spacing: 5
//                    width: chat.width
//                    height: chat.height

                    clip: true

                    model: MessageModel
                    {
                        list: messageList
                    }

                    delegate: RowLayout
                    {

                        width: parent.width
//                        height: parent.height
                        Layout.fillWidth: true

                        Rectangle
                        {
                            color: "lightgray"
                            width: chat.width
                            height: 50
                            id: message
                            Text {
                                id: text
                                text: qsTr(model.userName + ": " + model.text)
                            }
                            Text {
                                id: time
                                text: qsTr("text")
                            }
                            Layout.fillWidth: true

                        }

//                        TextField
//                        {
//                            text: model.text
//                            onEditingFinished: model.text = text
//                            Layout.fillWidth: true
//                        }
//                        TextField
//                        {
//                            text: model.userName
//                            onEditingFinished: model.userName = text
//                            Layout.fillWidth: true
//                        }

                    }
                }
            }
        }
    }



    Row {
        id: row
        x: chat.x
        y: chat.height + chat.y
        width: chat.width
        height: 50
        spacing: 5

        TextField
        {
            id: text_mess
            placeholderText: qsTr("Enter message")
            text: ""
            width: row.width - button.width - 5
            height: 50
        }

        Button
        {
            id: button
            height: 50
            width: te1.width + (te1.width * 0.9)
            Text
            {
                anchors.centerIn: parent
                id: te1
                text: "send"
            }

            onClicked:{
                if( message !== "")
                {
                    root.buttonClicked();
                    text_mess.text = "";
                }
            }
        }
    }





}




