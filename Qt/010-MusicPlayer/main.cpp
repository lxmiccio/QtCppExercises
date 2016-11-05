#include <QApplication>
#include <QFontDatabase>

#include "stackedwidget.h"

int main(int argc, char *argv[])
{
  QApplication application(argc, argv);

  QFontDatabase::addApplicationFont("fonts/RobotoCondensed-Light.ttf");

  StackedWidget stackedWidget;
  stackedWidget.show();

  return application.exec();
}
