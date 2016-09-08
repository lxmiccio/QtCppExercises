#include "firstwidget.h"

#include "basewidget.h"
#include "secondwidget.h"

FirstWidget::FirstWidget(QStackedWidget* stackedWidget, QWidget* parent) : BaseWidget(parent)
{
    this->stackedWidget = stackedWidget;

    this->message = new QLabel("First Window", this);
    this->message->setGeometry(QRect(QPoint(10, 10), QSize(100, 30)));

    this->button2 = new QPushButton("Go to Second Window", this);
    this->button2->setGeometry(QRect(QPoint(10, 50), QSize(200, 30)));

    QObject::connect(button2, SIGNAL(clicked()), this, SLOT(createSecondWidget()));
}

void FirstWidget::createSecondWidget()
{
    SecondWidget* secondWidget = new SecondWidget(this->stackedWidget);

    stackedWidget->addWidget(secondWidget);
    stackedWidget->setCurrentWidget(secondWidget);
}
