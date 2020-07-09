pragma Singleton
import QtQuick 2.0

Item {
    property alias contacts: _contacts
    QtObject {
        id: _contacts
        readonly property string defaultContactIcon: "qrc:/qml/resources/default_contact_icon.svg"
        readonly property string buttonInfoIcon: "qrc:/qml/resources/contact_info_icon.svg"
        readonly property string buttonPlusIcon: "qrc:/qml/resources/contact_plus_icon.svg"
        readonly property string callIcon: "qrc:/qml/resources/call_icon.svg"
    }
}
