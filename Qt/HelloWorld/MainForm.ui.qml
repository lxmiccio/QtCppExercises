import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
  id: page
  width: 640
  height: 480
  property alias mouseArea3: mouseArea3
  property alias bottomLeftRectangle: bottomLeftRectangle
  property alias mouseArea2: mouseArea2
  property alias middleRightRectangle: middleRightRectangle
  property alias mouseArea1: mouseArea1
  property alias topLeftRectangle: topLeftRectangle
  property alias icon: icon

  Image {
    id: icon
    x: 20
    y: 20
    width: 150
    height: 150
    source: "qt_logo.png"
  }

  Rectangle {
    id: topLeftRectangle
    width: 150
    height: 150
    color: "#00000000"
    anchors.left: parent.left
    anchors.leftMargin: 20
    anchors.top: parent.top
    anchors.topMargin: 20
    border.color: "#808080"

    MouseArea {
      id: mouseArea1
      anchors.fill: parent
    }
  }

  Rectangle {
    id: middleRightRectangle
    x: 490
    y: -8
    width: 150
    height: 150
    color: "#00000000"
    anchors.verticalCenterOffset: 0
    anchors.right: parent.right
    anchors.rightMargin: 20
    anchors.verticalCenter: parent.verticalCenter
    border.color: "#808080"
    MouseArea {
      id: mouseArea2
      anchors.fill: parent
    }
  }

  Rectangle {
      id: bottomLeftRectangle
      y: -1
      width: 150
      height: 150
      color: "#00000000"
      anchors.left: parent.left
      anchors.leftMargin: 20
      anchors.bottom: parent.bottom
      anchors.bottomMargin: 20
      border.color: "#808080"
      MouseArea {
        id: mouseArea3
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        anchors.bottomMargin: 0
        anchors.topMargin: 0
      }
  }

}
