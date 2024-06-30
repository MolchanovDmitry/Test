import QtQuick 2.0
import Sailfish.Silica 1.0
import QtQuick.Layouts 1.0

Page {
    objectName: "mainPage"
    allowedOrientations: Orientation.All

    PageHeader {
        objectName: "pageHeader"
        title: qsTr("Template")
        extraContent.children: [
            IconButton {
                objectName: "aboutButton"
                icon.source: "image://theme/icon-m-about"
                anchors.verticalCenter: parent.verticalCenter

                onClicked: pageStack.push(Qt.resolvedUrl("AboutPage.qml"))
            }
        ]
    }

    ListView {
        anchors.fill: parent
        model: weatherModel

        delegate: Item {
            width: parent.width
            height: 50

            RowLayout {
                anchors.fill: parent
                spacing: 10

                Text {
                    text: model.weekName
                    Layout.alignment: Qt.AlignLeft
                    Layout.fillWidth: true
                }

                Text {
                    text: {
                        var morning = model.morningTemp
                        var afternoon = model.afternoonTemp
                        var evening = model.eveningTemp
                        var average = (morning + afternoon + evening) / 3
                        return average.toFixed(1) + " °C"
                    }
                    Layout.alignment: Qt.AlignRight
                }
            }
        }
    }
}
