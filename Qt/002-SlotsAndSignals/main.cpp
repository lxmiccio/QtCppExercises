#include <iostream>

#include <QCoreApplication>

#include "counter.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QCoreApplication::setApplicationName("002-SlotsAndSignals");

  counter c;

  int x {0};
  std::cout << "Enter a value: ";
  std::cin >> x;

  c.setValue(x);

  return a.exec();
}
