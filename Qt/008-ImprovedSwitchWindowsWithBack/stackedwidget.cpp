#include "stackedwidget.h"

#include "basewidget.h"
#include "mainwidget.h"

StackedWidget::StackedWidget(QWidget *parent) : QMainWindow(parent)
{
    this->qStackedWidget = new QStackedWidget();

    QObject::connect(this->qStackedWidget, SIGNAL(currentChanged(int)),this, SLOT(goToNewWidget(int)));

    this->qStackedWidget->addWidget(new MainWidget(this));
    setCentralWidget(this->qStackedWidget);
}

void StackedWidget::goToNewWidget(int index)
{
    BaseWidget* currentWidget = static_cast<BaseWidget*>(this->qStackedWidget->widget(index));

    if(currentWidget) {
        currentWidget->setFocus();
    }
}

int StackedWidget::returnToPreviousWidget()
{
    int result = -1;

    QString currentWidgetName = this->qStackedWidget->currentWidget()->metaObject()->className();
    QString previousWidgetName;

    for(int i {this->qStackedWidget->count() - 1}; i >= 0; --i)
    {
        QWidget* widget = this->qStackedWidget->widget(i);

        if(widget->metaObject()->className() == currentWidgetName) {
            {
                --i;

                previousWidgetName = this->qStackedWidget->widget(i)->metaObject()->className();

                this->qStackedWidget->setCurrentWidget(this->qStackedWidget->widget(i));
                this->qStackedWidget->removeWidget(widget);

                delete widget;

                result = 0;
            }

            break;
        }
    }

    return result;
}
