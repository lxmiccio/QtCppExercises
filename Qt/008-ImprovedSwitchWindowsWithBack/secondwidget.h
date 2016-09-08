#ifndef SECONDWIDGET_H
#define SECONDWIDGET_H

#include <QLabel>
#include <QPushButton>

#include <basewidget.h>

class SecondWidget : public BaseWidget
{
protected:
    QLabel* message;
    QPushButton* button0;

public:
    explicit SecondWidget(StackedWidget* stackedWidget, QWidget* parent = 0);
};

#endif // SECONDWIDGET_H
