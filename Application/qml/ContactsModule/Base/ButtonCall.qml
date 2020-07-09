import QtQuick 2.0
import StyleSettings 1.0
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.3

Image {
    id: _buttonCall

    property alias image: _internalImage

    RoundImage {
        id: _internalImage
        anchors.fill: _buttonCall
        anchors.margins: Style.mediumOffset
        sourceSize.height: height
        sourceSize.width: width
    }

    MouseArea {
        id: _callArea
        anchors.fill: parent
        onClicked: {
            var factory = Qt.createComponent( "CallWindow.qml");
            factory.createObject( _buttonCall );
        }
    }
}
