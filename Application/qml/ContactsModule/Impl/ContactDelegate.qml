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
        width: root.height - 25
        height: root.height - 25
        image.source: Resources.contacts.callIcon
    }

    ButtonFavorite {
        id: _buttonFavorite
        anchors.right: _buttonCall.left
        anchors.rightMargin: Style.defaultOffset
        anchors.verticalCenter: root.verticalCenter
        width: root.height - 50
        height: root.height - 50

        source: isFavorite ? Resources.contacts.favoriteTrueIcon : Resources.contacts.favoriteFalseIcon

        property bool pressed: false

        MouseArea {
            id: mouse_area
            anchors.fill: parent

            onReleased: {
                _buttonFavorite.opacity = Style.defaultOpacity

                if (_buttonFavorite.pressed == false) {
                    _buttonFavorite.state = "FavoriteTrue"
                    _buttonFavorite.pressed = true
                }
                else{
                    _buttonFavorite.state = "FavoriteFalse"
                    _buttonFavorite.pressed = false
                }

            }
            onPressed: {
                _buttonFavorite.opacity = Style.disableOpacity

            }
        }

        states:[
            State {
                name: "FavoriteTrue"
                    PropertyChanges { target: _buttonFavorite; source: Resources.contacts.favoriteTrueIcon}
            },
            State {
                name: "FavoriteFalse"
                    PropertyChanges { target: _buttonFavorite; source: Resources.contacts.favoriteFalseIcon}
            }
        ]
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
