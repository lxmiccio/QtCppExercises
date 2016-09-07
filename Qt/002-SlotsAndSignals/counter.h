#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class counter
{
  private:
    int value;

  public:
    int getValue() const { return value; }

  public slots:
    void setValue(int value);

  signals:
    void valueChanged(counter* c);
};

#endif // COUNTER_H
