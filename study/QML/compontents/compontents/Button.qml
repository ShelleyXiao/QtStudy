import QtQuick 2.0

Rectangle {


    id: root

    property alias text: label.text
    signal clicked

    x:12; y:12

    width: 116; height: 26
    color: "#989790"
    border.color: "#856987"
    Text {
        id: label
        anchors.centerIn: parent
        text: "start"
    }

    MouseArea {
        anchors.fill: parent
        onClicked:  {
            status.text = "button clicked"
        }
    }


}
