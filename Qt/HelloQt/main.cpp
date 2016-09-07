#include <QApplication>
#include <QPushButton>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setApplicationName("Hello Qt");

    QWidget window;
    window.setFixedSize(220, 70);

    QPushButton *button = new QPushButton("Hello Qt", &window);
    button->setGeometry(10, 10, 200, 50);

    window.show();

    return a.exec();
}
