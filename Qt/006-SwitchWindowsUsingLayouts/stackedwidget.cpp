#include "stackedwidget.h"

#include "basewidget.h"
#include "mainwidget.h"

StackedWidget::StackedWidget(QWidget *parent) : QMainWindow(parent)
{
    this->stackedWidget = new QStackedWidget();

    QObject::connect(this->stackedWidget, SIGNAL(currentChanged(int)),this, SLOT(widgetChanged(int)));

    stackedWidget->addWidget(new MainWidget(stackedWidget));
    setCentralWidget(stackedWidget);
}

void StackedWidget::widgetChanged(int index)
{
    BaseWidget* currentWidget = static_cast<BaseWidget*>(stackedWidget->widget(index));

    if(currentWidget) {
        currentWidget->setFocus();
    }
}
