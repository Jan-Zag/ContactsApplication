import QtQuick 2.0
import ContactsModule.Base 1.0
import StyleSettings 1.0
import ResourceProvider 1.0

BaseListDelegate {
    id: root

    ImageBubble {
        id: _contactBubble
        anchors.left: root.left
        anchors.leftMargin: Style.defaultOffset
        anchors.verticalCenter: root.verticalCenter
        width: root.height - 10
        height: root.height - 10
        image.source: Resources.contacts.defaultContactIcon
    }

    ButtonCall {
        id: _buttonCall
        anchors.right: root.right
        anchors.rightMargin: Style.defaultOffset
        anchors.verticalCenter: root.verticalCenter
        width: root.height - 20
        height: root.height - 20
        image.source: Resources.contacts.callIcon
    }

    Column {
        anchors.verticalCenter: root.verticalCenter
        anchors.left: _contactBubble.right
        anchors.leftMargin: Style.defaultOffset
        anchors.rightMargin: Style.defaultOffset
        anchors.right: _buttonCall.left
        Row {
            spacing: Style.smallSpacing
            BaseText {
                text: name
            }
            BaseText {
                text: surname
            }
        }
        BaseText {
            text: "+" + phoneNumber
            color: Style.primaryColor
        }
    }
}
