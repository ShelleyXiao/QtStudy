﻿import QtQuick 2.0

Item {


    width: bg.width
    height: bg.height

    Image {
        id:bg
        source: "/images/images/videoplayer.jpg"
    }

    MouseArea {
        id:backgroundClicker

        anchors.fill: parent
        onClicked: {
            rocket1.x = 20
            rocket2.rotation = 0;
            rocket3.rotation = 0;
            rocket3.scale = 0
        }
    }

    ClickableImage {
        id: rocket1
        x: 20; y: 100
        source: "/images/images/rock.png"
        smooth: true
        onClicked: {
            x += 5
        }
    }

    ClickableImage {
        id: rocket2
        x: 140; y: 100
        source: "/images/images/rock.png"
        smooth: true
        onClicked: {
            rotation += 10
        }
    }

    ClickableImage {
        id: rocket3
        x: 240; y: 100
        source: "/images/images/rock.png"
        smooth: true
        onClicked: {
            rotation += 10
            scale -= 0.06
        }
    }
}
