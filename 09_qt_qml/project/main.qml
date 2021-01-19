import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

import pl.gwizdz 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Counter {
        id: counter
        onChanged: function() {
            console.info("Changed...")
        }
    }

    Dial {
        id: dial
        x: 67
        y: 148
        value: counter.value / 100.0
    }

    ProgressBar {
        id: progressBar
        x: 264
        y: 237
        value: dial.value
    }

    Text {
        id: element
        x: 264
        y: 162
        width: 200
        height: 48
        text: dial.value
        font.pixelSize: 12
    }

    Button {
        id: button
        x: 490
        y: 220
        text: qsTr("Clear")
        onClicked: function() {
            counter.value = 0
        }
    }

    Button {
        id: button1
        x: 490
        y: 328
        text: qsTr("Increment")
        onClicked: function() {
            counter.increment()
        }
    }

    Text {
        id: element1
        x: 264
        y: 341
        width: 200
        height: 27
        text: counter.value
        font.pixelSize: 12
    }
}
