#include "secondwidget.h"

#include "basewidget.h"

SecondWidget::SecondWidget(QStackedWidget* stackedWidget, QWidget* parent) : BaseWidget(parent)
{
    this->stackedWidget = stackedWidget;

    this->message = new QLabel("Second Window", this);
    this->message->setGeometry(QRect(QPoint(10, 10), QSize(100, 30)));
}
