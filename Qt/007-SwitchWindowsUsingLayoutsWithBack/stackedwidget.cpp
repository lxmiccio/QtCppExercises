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

int StackedWidget::previousView()
{
    int ret = -1;
        QString currentName = stackedWidget->currentWidget()->metaObject()->className();
        QString previous;

        for (int i=stackedWidget->count()-1;i>=0;i--)
            {
            QWidget* w = stackedWidget->widget(i);
            if (w->metaObject()->className()==currentName)
                {

                    {
                    i--;
                    previous = stackedWidget->widget(i)->metaObject()->className();
                    ret = 0;
                    stackedWidget->setCurrentWidget(stackedWidget->widget(i));
                    stackedWidget->removeWidget(w);
                    delete w;
                    // Activate prevous widget
                    //activateWidget(previous);
                    }
                break;
                }
            }
       return ret;
}
