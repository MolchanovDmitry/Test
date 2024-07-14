import QtQuick 2.0
import Sailfish.Silica 1.0
import QtQuick.Layouts 1.0

Page {
    id: detailsPage
    objectName: "detailsPage"
    allowedOrientations: Orientation.All

    property string dayTitle
    property string morningTemp
    property string afternoonTemp
    property string eveningTemp

    ListModel {
        id: temperaturesModel
    }

    Component.onCompleted: {
        temperaturesModel.append({
                                     "timeOfDay": qsTr("Утро"),
                                     "temperature": morningTemp
                                 })
        temperaturesModel.append({
                                     "timeOfDay": qsTr("День"),
                                     "temperature": afternoonTemp
                                 })
        temperaturesModel.append({
                                     "timeOfDay": qsTr("Вечер"),
                                     "temperature": eveningTemp
                                 })
    }

    Column {
        anchors.fill: parent
        anchors.leftMargin: Theme.horizontalPageMargin
        anchors.rightMargin: Theme.horizontalPageMargin

        PageHeader {
            id: pageHeader
            title: qsTr("Температура для ") + dayTitle
        }

        ListView {
            height: parent.height - pageHeader.height
            width: parent.width
            model: temperaturesModel

            delegate: Item {
                width: parent.width
                height: 50

                RowLayout {
                    anchors.fill: parent
                    spacing: 10

                    Text {
                        text: model.timeOfDay
                        Layout.alignment: Qt.AlignLeft
                        Layout.fillWidth: true
                        color: Theme.primaryColor
                    }

                    Text {
                        color: Theme.primaryColor
                        text: model.temperature + " °C"
                        Layout.alignment: Qt.AlignRight
                    }
                }
            }
        }
    }
}
