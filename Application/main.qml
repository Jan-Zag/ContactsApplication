import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
//import QtQuick.Controls.Styles 1.4
import StyleSettings 1.0
import ContactsModule.Impl 1.0
import ContactsModule.Base 1.0
import ResourceProvider 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Contact list")

    ContactsView {
        anchors.fill: parent
    }

    Rectangle {
        id: _background
        z: -100
        anchors.fill: parent
        color: Style.backgroundColor
        opacity: Style.emphasisOpacity
    }


    footer: ToolBar {
        RowLayout {
            anchors.fill: parent
            ToolButton {
                ButtonAdd {
                    id: _buttonAdd
                    anchors.fill: parent
                    image.source: Resources.contacts.buttonPlusIcon
                }
            }

        }
    }
}
