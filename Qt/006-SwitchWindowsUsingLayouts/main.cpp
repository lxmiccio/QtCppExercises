#include <QApplication>

#include <stackedwidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setApplicationName("005-SwitchWindows");

    StackedWidget w;
    w.show();

    return a.exec();
}
