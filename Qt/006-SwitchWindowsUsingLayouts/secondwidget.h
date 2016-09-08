#ifndef SECONDWIDGET_H
#define SECONDWIDGET_H

#include <QLabel>

#include <basewidget.h>

class SecondWidget : public BaseWidget
{
protected:
    QLabel* message;

public:
    explicit SecondWidget(QStackedWidget* stackedWidget, QWidget* parent = 0);
};

#endif // SECONDWIDGET_H
