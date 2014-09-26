import QtQuick 2.0
import org.kde.plasma.core 2.0 as PlasmaCore

Text {
    width: parent.width / parent.columns
    height: parent.buttonHeight
    horizontalAlignment: Qt.AlignHCenter
    verticalAlignment: Qt.AlignVCenter
    font.pixelSize: Math.floor((width - (units.largeSpacing)) / 2)
    property alias sub: longHold.text;

    MouseArea {
        anchors.fill: parent
        onClicked: {
            addNumber(parent.text);
        }

        onPressAndHold: {
            if (longHold.visible) {
                addNumber(longHold.text);
            } else {
                addNumber(parent.text);
            }
        }
    }

    Text {
        id: longHold
        visible: text.length > 0
        opacity: 0.7
        height: parent.height
        width: parent.width / 3
        verticalAlignment: Qt.AlignVCenter
        anchors {
            top: parent.top
            right: parent.right
        }

        font.pixelSize: parent.pixelSize * .8
    }
}
