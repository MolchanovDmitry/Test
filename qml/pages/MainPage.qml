import QtQuick 2.0
import Sailfish.Silica 1.0
import QtQuick.Layouts 1.0

Page {
    objectName: "mainPage"
    allowedOrientations: Orientation.All

    Column {
        anchors.fill: parent

        PageHeader {
            id: pageHeader
            title: qsTr("Template")
        }

        ListView {
            anchors {
                left: parent.left
                right: parent.right
                top: pageHeader.bottom
                bottom: parent.bottom
            }
            anchors.leftMargin: Theme.horizontalPageMargin
            anchors.rightMargin: Theme.horizontalPageMargin
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
                        color: Theme.primaryColor
                    }

                    Text {
                        color: Theme.primaryColor
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
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        pageStack.push(Qt.resolvedUrl("DetailsPage.qml"), {
                                           "dayTitle": model.weekName,
                                           "morningTemp": model.morningTemp,
                                           "afternoonTemp": model.afternoonTemp,
                                           "eveningTemp": model.eveningTemp
                                       })
                    }
                }
            }
        }
    }
}
