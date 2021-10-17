import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Rectangle
{
    property var buttonMode: TextField.Normal
    property string defualtText: defText.text
    property bool focusRec: strInput.focus
    property string input: strInput.text
    property int widRec: 50
    property string dT: ""


    id: rect
    width: widRec
    height: strInput.height + strInput.height/4
    color: "lightgray"
    border.color: "black"
    border.width: 1
    radius: 3

    TextField
    {
        id: strInput
        anchors.centerIn: parent
        width: rect.width - (rect.width /10)
        text: dT
        font.pixelSize: 14
        background: Rectangle
        {
            id: backgroundRect
            color: rect.color
        }
        echoMode: buttonMode
    }

    Text
    {
        id: defText
        anchors.centerIn: parent
        width: rect.width - (rect.width /10)
        visible: (strInput.focus || strInput.text != "")? false: true
        font.pixelSize: 14
        text: defualtText
    }
}
