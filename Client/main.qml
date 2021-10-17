import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0
Window {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

//        Connections {
//            target: gui // Указываем целевой объект для соединения
//            /* Объявляем и реализуем функцию, как параметр
//             * объекта и с имененем похожим на название сигнала
//             * Разница в том, что добавляем в начале on и далее пишем
//             * с заглавной буквы
//             * */
//            onTo_gui: {
//                labelCount.text = count // Устанавливаем счётчик в текстовый лейбл
//            }
//        }


//        Label {
//            id: labelCount
//            text: "0"

//            anchors.bottom: parent.verticalCenter
//            anchors.horizontalCenter: parent.horizontalCenter
//            anchors.bottomMargin: 15
//        }

//        Button {
//            text: qsTr("Increase counter")
//            onClicked: gui.from_gui() // Вызов слота

//            anchors.top: parent.verticalCenter
//            anchors.horizontalCenter: parent.horizontalCenter
//        }
    /////////////////////////////////////////////////////////////////////////////
//    Label
//    {
//        id: labelCount
//        text: gui.counter

//        anchors.bottom: parent.verticalCenter
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.bottomMargin: 15
//    }

//    Button
//    {
//        text: qsTr("Increase counter")
//        onClicked: ++gui.counter

//        anchors.top: parent.verticalCenter
//        anchors.horizontalCenter: parent.horizontalCenter
//    }
    ////////////////////////////////////////////////////////////////////////////////
//    property int counter: 0

//    // Метод для манипуляций со счётчиком
//    function inrementCounter()
//    {
//        ++counter;
//    }
//    function deinrementCounter()
//    {
//        --counter;
//    }

//    Label {
//        id: labelCount
//        text: mainWindow.counter

//        anchors.bottom: parent.verticalCenter
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.bottomMargin: 15
//    }

//    Row
//    {
//        anchors.fill: parent
//        Button {
//            id: button
//            text: qsTr("Increase counter")

//            Component.onCompleted: {
//                // Когда кнопка создана, то подключим сигнал клика по кнопке
//                // к методу для увеличения счетчика в окне приложения
//                button.clicked.connect(mainWindow.inrementCounter)
//            }
//        }
//        Button {
//            id: button2
//            text: qsTr("deIncrease counter")

//            Component.onCompleted: {
//                // Когда кнопка создана, то подключим сигнал клика по кнопке
//                // к методу для увеличения счетчика в окне приложения
//                button2.clicked.connect(mainWindow.deinrementCounter)
//            }
//        }
//    }
    /////////////////////////////////////////////////////////////////////////////////

//    RowLayout
//    {
//        anchors.fill: parent
//        anchors.margins: 10

//        Label{text: "Введите IP-адрес"}
//        TextField
//        {
//            validator: RegExpValidator{regExp:  /^((?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\.){0,3}(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])$/}
//        }

//        Label{ text: "Введите почту"}
//        TextField
//        {
//            validator: RegExpValidator {regExp:  /^([a-z]{2,10}[0-9]{1,5})(@[\w-]+\.[a-z]{2,5}$)/}
//        }
//    }
    ///////////////////////////////////////////////////////////////////////////////////

    property int defMargin: 10
    property string username: ""

    Connections
    {
        target: gui
        onTo_authorization:
        {
            if (auth == true) // Устанавливаем счётчик в текстовый лейбл
            {
                stackView.push(page2);
            }
            else
                stackView.pop(page1);
        }
    }



    StackView
    {
        id: stackView
        anchors.fill: parent
        initialItem: page1
    }


    PageLogin
    {
        id: page1
        onButtonClicked:{gui.authorization(page1.userName, page1.password);}
    }
    SimplePage
    {
        id: page2
        visible:  false
        backgroundColor: "red"
        buttonText: "Next"

        onButtonClicked:{stackView.push(page3);}
    }
    SimplePage
    {
        id: page3
        visible:  false
        backgroundColor: "blue"
        buttonText: "Back"

        onButtonClicked:{stackView.pop(page1);}
    }

}
