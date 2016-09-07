#include <QCoreApplication>

#include "counter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    counter c;

    c.setValue(5);

    return a.exec();
}
