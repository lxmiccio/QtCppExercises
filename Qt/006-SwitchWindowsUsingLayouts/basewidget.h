#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QStackedWidget>
#include <QWidget>

class BaseWidget : public QWidget
{
protected:
    QStackedWidget* stackedWidget;

public:
    explicit BaseWidget(QWidget* parent = 0);
};

#endif // BASEWIDGET_H
