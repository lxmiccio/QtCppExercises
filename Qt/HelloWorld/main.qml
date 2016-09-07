import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2

ApplicationWindow {
  visible: true
  width: 480
  height: 480
  title: qsTr("Transitions")

  menuBar: MenuBar {
    Menu {
      title: qsTr("File")
      MenuItem {
        text: qsTr("&Open")
        onTriggered: console.log("Open action triggered");
      }
      MenuItem {
        text: qsTr("Exit")
        onTriggered: Qt.quit();
      }
    }
  }

  MainForm {
    anchors.fill: parent
    id: page

    mouseArea1.onClicked: stateGroup.state = ' '
    mouseArea2.onClicked: stateGroup.state = 'State1'
    mouseArea3.onClicked: stateGroup.state = 'State2'
  }

  StateGroup {
    id: stateGroup

    states: [
      State {
        name: "State1"

        PropertyChanges {
          target: page.icon
          x: page.middleRightRectangle.x
          y: page.middleRightRectangle.y
        }
      },
      State {
        name: "State2"

        PropertyChanges {
          target: page.icon
          x: page.bottomLeftRectangle.x
          y: page.bottomLeftRectangle.y
        }
      }
    ]

    transitions: [
      Transition {
        from: "*"; to: "State1"
        NumberAnimation {
          easing.type: Easing.OutBounce
          properties: "x,y";
          duration: 1000
        }
      },
      Transition {
        from: "*"; to: "State2"
        NumberAnimation {
          properties: "x,y";
          easing.type: Easing.InOutQuad;
          duration: 2000
        }
      },
      Transition {
        NumberAnimation {
          properties: "x,y";
          duration: 200
        }
      }
    ]
  }

MessageDialog {
  id: messageDialog
  title: qsTr("May I have your attention, please?")

  function show(caption) {
    messageDialog.text = caption;
    messageDialog.open();
  }
}
}
