import QtQuick 2.0

Item {
    Rectangle {
        id: rectangleLed
        x: 0
        y: 0
        width: 20
        height: 20
        color: "#994141"
        border.width: 3

        anchors.top: parent
        anchors.right: parent
    }

    Connections{
        slot_on: {
            rectangleLed.color: "123"
        }
        slot_off: {

        }
    }


}
