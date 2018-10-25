import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

//    ClickableImageV2 {
//        id: rocket1
//        x: 40; y: 200
//        source: "assets/rocket.png"
//        text: "animation on property"
//        NumberAnimation on y {
//            to: 40; duration: 4000
//        }
//    }

//    ClickableImageV2 {
//        id: rocket2
//        x: 152; y: 200
//        source: "assets/rocket.png"
//        text: "behavior on property"
//        Behavior on y {
//            NumberAnimation {
//                duration: 4000
//            }
//        }

////        onClicked: y = 40
//        onClicked: y  = 40 + Math.random() * (205 - 40)

//    }

//    ClickableImageV2 {
//        id: rocket3
//        x: 264; y: 200
//        source: "assets/rocket.png"
//        onClicked: anim.start()

//        text: "standalone animation"

//        NumberAnimation {
//            id: anim
//            target: rocket3
//            properties: "y"
//            from: 205
//            to: 40
//            duration: 4000

//            running: area.pressed
//        }
//    }

    EasingTypes {}

    MouseArea {
        id: area
    }
}
