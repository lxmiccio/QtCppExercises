#include "secondwidget.h"

#include "basewidget.h"

#include <QGridLayout>

SecondWidget::SecondWidget(QStackedWidget* stackedWidget, QWidget* parent) : BaseWidget(parent)
{
    this->stackedWidget = stackedWidget;

    this->message = new QLabel("Second Window", this);
    this->message->setAlignment(Qt::AlignCenter);

    QGridLayout *gridLayout = new QGridLayout;

    gridLayout->addWidget(this->message);

    setLayout(gridLayout);
}
