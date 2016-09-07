#include <iostream>

#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

#include "counter.h"

void counter::setValue(int value)
{
  this->value = value;

  emit(valueChanged(this));
}

void counter::valueChanged(counter* c)
{
  QDateTime dateTime {QDateTime::currentDateTime()};
  QString time {dateTime.toString("dd-MM-yyyy HH:mm:ss:zzz")};

  QString message {QString("You entered %1").arg(c->getValue())};

  QFile out("log.log");
  out.open(QIODevice::WriteOnly | QIODevice::Append);

  QTextStream textStream(&out);
  textStream << time << ": " << message << endl;
}
