import QtQuick 2.0
import StyleSettings 1.0
import QtGraphicalEffects 1.0
import QtQuick.Controls 2.3

Image {
    id: _buttonAdd

    property alias image: _internalImage

    RoundImage {
        id: _internalImage
        anchors.fill: _buttonAdd
        anchors.margins: Style.mediumOffset
        sourceSize.height: height
        sourceSize.width: width
    }

    MouseArea {
        id: _addArea
        anchors.fill: parent
        onClicked: {
            var factory = Qt.createComponent( "AddContactWindow.qml");
            factory.createObject( _buttonAdd );
        }
    }
}
