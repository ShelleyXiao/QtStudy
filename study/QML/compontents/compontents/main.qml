import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
    }

    TextEdit {
        id: textEdit
        text: qsTr("Enter some text...")
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
        }
    }

    Button {
        id: button
        x: 12;  y: 12
        text: "Start"
        onClicked: {
            status.text="Button Clicked"
        }

    }

    Text {
        id: status
        x: 56; y: 156
        width: 116; height: 26
        text: "waiting..."
        horizontalAlignment: Text.AlignHCenter
    }
}
