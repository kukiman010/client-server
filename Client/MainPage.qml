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
    property string username: left_bar.width + " " + left_bar.height

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
        x: left_bar.height + 10
        y: top_bar.height + 5
        ColumnLayout
        {
            anchors.centerIn: parent
            Frame
            {
                Layout.fillWidth: true

                ListView
                {
                    implicitWidth: 300
                    implicitHeight: 250
                    anchors.fill: parent
                    clip: true

                    model: MessageModel
                    {
                        list: messageList
                    }

                    delegate: RowLayout
                    {
                        width: parent.width

    //                    CheckBox
    //                    {
    //                        checked: model.done
    //                        onClicked: model.done = checked
    //                    }

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
    }
}
