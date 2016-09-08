#include "firstwidget.h"

#include "basewidget.h"
#include "secondwidget.h"

#include <QGridLayout>

FirstWidget::FirstWidget(StackedWidget* stackedWidget, QWidget* parent) : BaseWidget(parent)
{
    this->stackedWidget = stackedWidget;

    this->message = new QLabel("First Window", this);
    this->message->setAlignment(Qt::AlignCenter);

    this->button0 = new QPushButton("Go to Previous Window", this);
    QObject::connect(button0, SIGNAL(clicked()), this->stackedWidget, SLOT(returnToPreviousWidget()));

    this->button2 = new QPushButton("Go to Second Window", this);
    QObject::connect(button2, SIGNAL(clicked()), this, SLOT(createSecondWidget()));

    QGridLayout *gridLayout = new QGridLayout;

    gridLayout->addWidget(this->message, 0, 0, 1, 1);
    gridLayout->addWidget(this->button0, 1, 0, 1, 1);
    gridLayout->addWidget(this->button2, 2, 0, 1, 1);

    setLayout(gridLayout);
}

void FirstWidget::createSecondWidget()
{
    SecondWidget* secondWidget = new SecondWidget(this->stackedWidget);

    this->stackedWidget->getQStackedWidget()->addWidget(secondWidget);
    this->stackedWidget->getQStackedWidget()->setCurrentWidget(secondWidget);
}
