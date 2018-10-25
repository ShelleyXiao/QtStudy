import QtQuick 2.6
import QtQuick.Window 2.2

Window {

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    Text {
        id: test1
        width: 40; height: 120
        text: 'a very long text'
        elide: Text.ElideMiddle
        style: Text.Sunken
        styleColor: '#809765'
        verticalAlignment: Text.AlignTop
        color: "#303030"
        font.family: "Ubuntu"
        font.pixelSize: 32
    }
}
