import QtQuick 2.6
import QtQuick.Window 2.2

Window {

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: rect1
        x: 12; y: 12
        width: 76; height: 96
        color: "lightsteelblue"

        MouseArea {
            id: area
            width: parent.width
            height: parent.width
            onClicked: rect1.visible = !rect2.visible
        }

    }

    Rectangle {
        id: rect2
        x: 112; y: 12
        width: 76; height: 96
        border.color: "lightsteelblue"
        border.width: 4
        radius: 8
    }

    Rectangle {
        id: rect3
        x: 220; y: 12
        width: 76; height: 96
        gradient: Gradient {
            GradientStop {position: 0.0; color: "#009900"}
            GradientStop {position: 1.0; color: "#887766"}
        }
        border.color: "slategray"
    }

}
