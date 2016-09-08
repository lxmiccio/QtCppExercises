#include "firstwidget.h"

#include "basewidget.h"
#include "secondwidget.h"

#include <QGridLayout>

FirstWidget::FirstWidget(QStackedWidget* stackedWidget, QWidget* parent) : BaseWidget(parent)
{
    this->stackedWidget = stackedWidget;

    this->message = new QLabel("First Window", this);
    this->message->setAlignment(Qt::AlignCenter);

    this->button1 = new QPushButton("Go Back [To You]");

    QObject::connect(this->button1, SIGNAL(clicked()), this, SLOT(previousView()));

    this->button2 = new QPushButton("Go to Second Window", this);

    QObject::connect(button2, SIGNAL(clicked()), this, SLOT(createSecondWidget()));

    QGridLayout *gridLayout = new QGridLayout;

    gridLayout->addWidget(this->message, 0, 0, 1, 1);
    gridLayout->addWidget(this->button1, 1, 0, 1, 1);
    gridLayout->addWidget(this->button2, 2, 0, 1, 1);

    setLayout(gridLayout);
}

void FirstWidget::createSecondWidget()
{
    SecondWidget* secondWidget = new SecondWidget(this->stackedWidget);

    stackedWidget->addWidget(secondWidget);
    stackedWidget->setCurrentWidget(secondWidget);
}

int FirstWidget::previousView()
{
    int result = -1;

    QString currentWidgetName = this->stackedWidget->currentWidget()->metaObject()->className();
    QString previousWidgetName;

    for(int i {this->stackedWidget->count() - 1}; i >= 0; --i)
    {
        QWidget* widget = this->stackedWidget->widget(i);

        if(widget->metaObject()->className() == currentWidgetName) {
            {
                --i;

                previousWidgetName = this->stackedWidget->widget(i)->metaObject()->className();

                this->stackedWidget->setCurrentWidget(this->stackedWidget->widget(i));
                this->stackedWidget->removeWidget(widget);

                delete widget;

                result = 0;
            }

            break;
        }
    }

    return result;
}
