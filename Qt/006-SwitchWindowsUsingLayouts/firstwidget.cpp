#include "firstwidget.h"

#include "basewidget.h"
#include "secondwidget.h"

#include <QGridLayout>

FirstWidget::FirstWidget(QStackedWidget* stackedWidget, QWidget* parent) : BaseWidget(parent)
{
    this->stackedWidget = stackedWidget;

    this->message = new QLabel("First Window", this);
    this->message->setAlignment(Qt::AlignCenter);

    this->button2 = new QPushButton("Go to Second Window", this);

    QObject::connect(button2, SIGNAL(clicked()), this, SLOT(createSecondWidget()));

    QGridLayout *gridLayout = new QGridLayout;

    gridLayout->addWidget(this->message, 0, 0, 1, 1);
    gridLayout->addWidget(this->button2, 1, 0, 1, 1);

    setLayout(gridLayout);
}

void FirstWidget::createSecondWidget()
{
    SecondWidget* secondWidget = new SecondWidget(this->stackedWidget);

    stackedWidget->addWidget(secondWidget);
    stackedWidget->setCurrentWidget(secondWidget);
}
