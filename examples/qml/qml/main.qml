import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import QtQuick.Layouts 1.14
import QRCode 1.0

ApplicationWindow {
    id: appWnd
    title: qsTr("QR Code QML")
    width: 500
    height: 500+toolbar.height
    readonly property real horizontalMargin: 8
    visible: true
    Material.theme: Material.Dark

    header: ToolBar {
        id: toolbar
        height: 100
        ButtonGroup { id: radioGroup }
        ColumnLayout {
            anchors.fill: parent
            RowLayout {
                RadioButton {
                    id: checkImage
                    ButtonGroup.group: radioGroup
                    text: "Image"
                    checked: true
                }
                Label {
                    Layout.leftMargin: appWnd.horizontalMargin
                    text: qsTr("QR-text1:")
                    color: Material.primaryTextColor
                }
                TextField {
                    id: qrCodeTextField1
                    Layout.fillWidth: true
                    Layout.bottomMargin: -8
                    color: Material.primaryTextColor
                }
            }
            RowLayout {
                RadioButton {
                    id: checkItem
                    Layout.preferredWidth: checkImage.width
                    ButtonGroup.group: radioGroup
                    text: "Item"
                }
                Label {
                    Layout.leftMargin: appWnd.horizontalMargin
                    text: qsTr("QR-text2:")
                    color: Material.primaryTextColor
                }
                TextField {
                    id: qrCodeTextField2
                    Layout.fillWidth: true
                    Layout.bottomMargin: -8
                    color: Material.primaryTextColor
                }
            }
        }
    }
    RowLayout {
        anchors.topMargin: 4
        anchors.fill: parent
        Image {
            Layout.fillHeight: true
            Layout.fillWidth: true
            fillMode: Image.PreserveAspectFit
            source: "image://qrcodeprovider/" + qrCodeTextField1.text
            visible: checkImage.checked
        }
        Image {
            Layout.fillHeight: true
            Layout.fillWidth: true
            fillMode: Image.PreserveAspectFit
            source: "image://qrcodeprovider/" + qrCodeTextField2.text
            visible: checkImage.checked
        }
        QRCodeItem {
            Layout.fillHeight: true
            Layout.fillWidth: true
            qrCodeText: qrCodeTextField1.text
            visible: checkItem.checked
        }
        QRCodeItem {
            Layout.fillHeight: true
            Layout.fillWidth: true
            qrCodeText: qrCodeTextField2.text
            visible: checkItem.checked
        }
    }


}
