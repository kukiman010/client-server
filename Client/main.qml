import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.0

import Message 1.0

Window {
    id: mainWindow
    visible: true
    minimumWidth: 640
        minimumHeight: 480
//    width: 640
//    height: 480
    title: qsTr("Hello World")
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//    readonly property int responsiveWidth: 500
//    SwipeView  {
//            id: swipeView
//            currentIndex: 1
//            anchors.fill: parent
//            states: [
//                State {
//                    when: window.width >= responsiveWidth
//                    ParentChange { target: contacts; parent: contactsContainer; }
//                    ParentChange { target: chat; parent: chatContainer; }
//                    PropertyChanges { target: indicator; visible: hide }
//                }
//            ]
//            Item {
//                Rectangle {
//                    id: contacts
//                    anchors.fill: parent
//                    color: "lightblue"; border.width: 5; border.color: "white"
//                }
//            }
//            Item {
//                Rectangle{
//                    id: chat
//                    anchors.fill: parent
//                    color: "lightgray"; border.width: 5; border.color: "white"
//                }
//            }
//        }

//        PageIndicator {
//            id: indicator
//            count: swipeView.count
//            currentIndex: swipeView.currentIndex
//            anchors.bottom: swipeView.bottom
//            anchors.bottomMargin: 10
//            anchors.horizontalCenter: swipeView.horizontalCenter
//        }

//        Row {
//            id: splitView
//            anchors.fill: parent
//            Item {
//                id: contactsContainer
//                width: parent.width / 2; height: parent.height
//            }
//            Item {
//                id: chatContainer
//                width: parent.width / 2; height: parent.height
//            }
//        }
    /////////////////////////////////////////////////////////////////////////////////////////

    property int defMargin: 10
    property string username: ""

    Connections
    {
        target: gui
        onTo_authorization:
        {
            if (auth == true)
                stackView.push(page2);
            else
                stackView.pop(page1);
        }
    }



    StackView
    {
        id: stackView
        anchors.fill: parent
//        initialItem: page1
        initialItem: pageMainMenu
    }


    PageLogin
    {
        id: page1
        visible:  false// убрать
        onButtonClicked:{gui.authorization(page1.userName, page1.password);}
    }
    SimplePage
    {
        id: page2
        visible:  false
        backgroundColor: "red"
        buttonText: "Next"

        onButtonClicked:{stackView.push(page3);}

        ScrollView
        {
            anchors.fill: parent

            ListView {
                width: parent.width
                model: 10
                delegate: ItemDelegate {
                    text: "Item " + (index + 1)
                    width: parent.width
                }
            }
        }
    }
    SimplePage
    {
        id: page3
        visible:  false
        backgroundColor: "blue"
        buttonText: "Back"

        onButtonClicked:{stackView.pop(page1);}
    }


    MainPage
    {
        id: pageMainMenu
    }
//    Rectangle
//    {
//        id: top_bar
////        anchors.top: root.top
////        anchors.left: root.left
////        anchors.right: root.right
//        height: 50
//        width: 50
//        color: "green"
//    }

}
