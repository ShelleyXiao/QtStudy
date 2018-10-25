import QtQuick 2.0

Image {
    id:root
    source: "asserts/air_hockey_surface.png"


    Image {
        id:anim
        source: "asserts/air_hockey_surface.png"
        x: 40; y: 40

        NumberAnimation on x{
          to: 240
          duration: 4000
          loops: Animation.Infinite
        }

        RotationAnimation on rotation {
            to: 360
            duration: 4000
            loops: Animation.Infinite
        }
    }
}
