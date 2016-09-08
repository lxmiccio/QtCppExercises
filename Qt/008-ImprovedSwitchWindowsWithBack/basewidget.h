#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <stackedwidget.h>

class BaseWidget : public QWidget
{
protected:
    StackedWidget *stackedWidget;

public:
    explicit BaseWidget(QWidget* parent = 0);
};

#endif // BASEWIDGET_H
