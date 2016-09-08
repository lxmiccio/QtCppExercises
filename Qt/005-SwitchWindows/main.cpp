#include <QApplication>

#include <stackedwidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setApplicationName("005-SwitchWindows");

    StackedWidget w;
    w.setFixedSize(QSize(500, 300));
    w.show();

    return a.exec();
}
