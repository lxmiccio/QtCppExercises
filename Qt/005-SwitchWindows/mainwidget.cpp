#include "mainwidget.h"

#include "basewidget.h"
#include "firstwidget.h"
#include "secondwidget.h"

MainWidget::MainWidget(QStackedWidget* stackedWidget, QWidget *parent) : BaseWidget(parent)
{
    this->stackedWidget = stackedWidget;

    this->message = new QLabel("Main Window", this);
    this->message->setGeometry(QRect(QPoint(10, 10), QSize(100, 30)));

    this->button1 = new QPushButton("Go to First Window", this);
    this->button1->setGeometry(QRect(QPoint(10, 50), QSize(200, 30)));
    QObject::connect(button1, SIGNAL(clicked()), this, SLOT(createFirstWidget()));

    this->button2 = new QPushButton("Go to Second Window", this);
    this->button2->setGeometry(QRect(QPoint(10, 90), QSize(200, 30)));
    QObject::connect(button2, SIGNAL(clicked()), this, SLOT(createSecondWidget()));
}

void MainWidget::createFirstWidget()
{
    FirstWidget* firstWidget = new FirstWidget(this->stackedWidget);

    this->stackedWidget->addWidget(firstWidget);
    this->stackedWidget->setCurrentWidget(firstWidget);
}

void MainWidget::createSecondWidget()
{
    SecondWidget* secondWidget = new SecondWidget(this->stackedWidget);

    this->stackedWidget->addWidget(secondWidget);
    this->stackedWidget->setCurrentWidget(secondWidget);
}
