import QtQuick 2.0
import QtQuick.Window 2.12
import StyleSettings 1.0

Window {
       height: 200
       width: 200
       title: qsTr( "Calling" )
       visible: true
       color: Style.backgroundColor

       Text {
           text: name + qsTr("  Calling...")
           anchors.centerIn: parent
           color: Style.primaryColor
       }
}
