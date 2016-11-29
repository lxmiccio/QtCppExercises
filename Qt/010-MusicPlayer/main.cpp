#include <QApplication>
#include <QFontDatabase>

#include "StackedWidget.h"
#include <QMap>

int main(int argc, char *argv[])
{
  QApplication application(argc, argv);

  QFontDatabase::addApplicationFont("fonts/Sniglet-Regular.ttf");

  QFont font = QApplication::font();
  font.setStyleStrategy(QFont::PreferAntialias);
  font.setFamily("Sniglet");
  font.setPointSize(9);
  QApplication::setFont(font);

  StackedWidget stackedWidget;
  stackedWidget.show();

  return application.exec();
}
