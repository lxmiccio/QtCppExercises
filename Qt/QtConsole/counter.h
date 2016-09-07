#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class counter
{
protected:
    int value;

public:
    int const getValue() { return value; }

public slots:
    void setValue(int value);

signals:
    void valueChanged(int value);
};

#endif // COUNTER_H
