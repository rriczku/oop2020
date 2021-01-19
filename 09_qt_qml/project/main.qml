import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

import pl.gwizdz 1.0
import pl.jrychu 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Displacement {
        id:displacement
        onChanged: function(){
            speed.changed(displacement.value);
            acceleration.changed(displacement.value);
        }
    }

    Speed {
        id:speed
    }

    Acceleration{
        id:acceleration
    }

    //acceleration
    Dial {
        id: dial
        x: 36
        y: 148
        from : -100
        to : 100
        Behavior on value { SpringAnimation { spring: 2; damping: 0.1 } }
    }
    //speed
    Dial {
        id: dial1
        x: 415
        y: 148
        from: 0
        to:100

        Behavior on value { SpringAnimation { spring: 2; damping: 0.1 } }

    }

    Text {
        id: element
        x: 91
        y: 345
        text: qsTr("Acceleration")
        font.pixelSize: 12
    }

    Text {
        id: element1
        x: 488
        y: 345
        text: qsTr("Speed")
        font.pixelSize: 12
    }
    //displacement
    Slider {
        id: slider
        x: 220
        y: 400
        from:-50
        to:50
        value:0

        onMoved: function(){
            displacement.set(value)
            dial.value=acceleration.get();
            dial1.value=speed.get();
        }
    }

    Text {
        id: element2
        x: 279
        y: 446
        text: qsTr("Displacement")
        font.pixelSize: 12
    }
}
