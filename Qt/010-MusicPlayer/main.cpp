#include <QApplication>

#include "stackedwidget.h"
#include "audiocontrols.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  StackedWidget stackedWidget;
  stackedWidget.show();

  return a.exec();
}
