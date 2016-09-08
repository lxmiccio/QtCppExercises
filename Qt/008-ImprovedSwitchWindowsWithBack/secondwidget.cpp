#include "secondwidget.h"

#include "basewidget.h"

#include <QGridLayout>

SecondWidget::SecondWidget(StackedWidget* stackedWidget, QWidget* parent) : BaseWidget(parent)
{
    this->stackedWidget = stackedWidget;

    this->message = new QLabel("Second Window", this);
    this->message->setAlignment(Qt::AlignCenter);

    this->button0 = new QPushButton("Go Back [To You]");
    QObject::connect(this->button0, SIGNAL(clicked()), this->stackedWidget, SLOT(returnToPreviousWidget()));

    QGridLayout *gridLayout = new QGridLayout;

    gridLayout->addWidget(this->message, 0, 0, 1, 1);
    gridLayout->addWidget(this->button0, 1, 0, 1, 1);

    setLayout(gridLayout);
}
