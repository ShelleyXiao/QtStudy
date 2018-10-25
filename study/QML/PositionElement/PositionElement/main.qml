import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: grids.width
    height: grids.height
    title: qsTr("Hello World")

    Repeaters {
        id: grids
    }
}
