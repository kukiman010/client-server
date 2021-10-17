import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0

Page
{
    id: root
    property alias backgroundColor: backgroundRect.color
    property string userName: user.input
    property string password: pass.input
    signal buttonClicked();

    background: Rectangle{id: backgroundRect}

    Rectangle
    {
        id: def_rec
        x: root.width/3
        y:  root.height/5
        width: root.width/3
        height: root.height/2

        border.color: "black"
        border.width: 2

        Column
        {
            anchors.fill: parent
            spacing: 10
            topPadding: 10
            leftPadding: 10

            PAGEONE
            {
                id: user
                widRec: def_rec.width - 20
                defualtText: "User Name"
            }
            PAGEONE
            {
                id: pass
                widRec: def_rec.width - 20
                defualtText: "Password"
                buttonMode: TextInput.Password;
            }
            Button
            {
                id: navButton
                text: "Вход"
                onClicked:{root.buttonClicked();}
            }
        }
    }


}
