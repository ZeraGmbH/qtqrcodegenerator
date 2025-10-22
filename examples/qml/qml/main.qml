import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.14
import QtQuick.Layouts 1.14

ApplicationWindow {
    id: appWnd
    title: qsTr("QR Code QML")
    width: 500
    height: 500+toolbar.implicitHeight
    readonly property real horizontalMargin: 8
    visible: true
    Material.theme: Material.Dark

    header: ToolBar {
        id: toolbar
        RowLayout {
            anchors.fill: parent
            Label {
                Layout.leftMargin: appWnd.horizontalMargin
                text: qsTr("QR-code text:")
                color: Material.primaryTextColor
            }
            TextField {
                id: qrCodeTextField
                Layout.fillWidth: true
                Layout.bottomMargin: -8
                color: Material.primaryTextColor
            }
        }
    }
    Image {
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        source: "image://qrcodeprovider/" + qrCodeTextField.text
    }
}
