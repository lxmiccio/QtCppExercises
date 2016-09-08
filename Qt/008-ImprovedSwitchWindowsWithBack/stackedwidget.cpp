#include "stackedwidget.h"

#include "basewidget.h"
#include "mainwidget.h"
#include <QDebug>
#include <iostream>

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

void StackedWidget::returnToPreviousWidget()
{
    QString currentWidgetName = this->qStackedWidget->currentWidget()->metaObject()->className();

    bool exit {false};

    for(int i {this->qStackedWidget->count() - 1}; i >= 0 and not exit; --i)
    {
        QWidget* widget = this->qStackedWidget->widget(i);

        if(widget->metaObject()->className() == currentWidgetName) {
            this->qStackedWidget->removeWidget(widget);
            delete widget;
        } else {
            this->qStackedWidget->setCurrentWidget(this->qStackedWidget->widget(i));
            exit = true;
        }
    }
}

void StackedWidget::returnToMainWidget()
{
    QString currentWidgetName = this->qStackedWidget->currentWidget()->metaObject()->className();

    for(int i {this->qStackedWidget->count() - 1}; i > 0; --i)
    {
        QWidget* widget = this->qStackedWidget->widget(i);

        this->qStackedWidget->removeWidget(widget);
        delete widget;
    }

    this->qStackedWidget->setCurrentWidget(this->qStackedWidget->widget(0));
}

