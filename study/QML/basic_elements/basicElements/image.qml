import QtQuick 2.0
import QtQuick.Window 2.0

Window {
    visible: true
    width: 640; height: 480

    Image {
        x: 12; y: 12
        source: "assert/test.jpg"
        clip: true
    }
}
