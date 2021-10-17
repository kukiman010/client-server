import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0

Page
{
    id: root
    property alias backgroundColor: backgroundRect.color
    property alias buttonText: navButton.text
    signal buttonClicked();

    background: Rectangle
    {
        id: backgroundRect
    }

    Button
    {
        id: navButton
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: defMargin
        onClicked:
        {
            root.buttonClicked();
        }
    }
}
