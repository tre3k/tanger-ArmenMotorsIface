import QtQuick 2.0

Item {
    Connections{
        target: appCore
    }

    Rectangle {
        id: rectangleLed
        x: 175
        y: 232
        width: 21
        height: 20
        color: "#994141"
        border.width: 3
    }

}
