import QtQuick 2.0

Item {
    id : root
    width: container.childrenRect.width
    height: container.childrenRect.height

    property alias text: label.text
    property alias source: image.source

    property bool framed: false

     signal clicked

    Column {
        id: container

        Image {
            id: image
        }

        Text {
            id: label
            width: image.width
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WordWrap
            color: "#111111"
        }
    }

    Rectangle {
        anchors.fill: parent
        color: "white"
        visible: root.framed
    }

    MouseArea {
       anchors.fill: parent
       onClicked: root.clicked()
    }
}
