#include "mainwidget.h"

#include "basewidget.h"
#include "firstwidget.h"
#include "secondwidget.h"

#include <QGridLayout>

MainWidget::MainWidget(QStackedWidget* stackedWidget, QWidget *parent) : BaseWidget(parent)
{
    this->stackedWidget = stackedWidget;

    this->message = new QLabel("Main Window", this);
    this->message->setAlignment(Qt::AlignCenter);

    this->button1 = new QPushButton("Go to First Window", this);
    QObject::connect(button1, SIGNAL(clicked()), this, SLOT(createFirstWidget()));

    this->button2 = new QPushButton("Go to Second Window", this);
    QObject::connect(button2, SIGNAL(clicked()), this, SLOT(createSecondWidget()));

    QGridLayout *gridLayout = new QGridLayout;

    gridLayout->addWidget(this->message, 0, 0, 1, 2);
    gridLayout->addWidget(this->button1, 1, 0, 1, 1);
    gridLayout->addWidget(this->button2, 1, 1, 1, 1);

    setLayout(gridLayout);
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
