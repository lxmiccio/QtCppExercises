#include "stackedwidget.h"

#include "mainwindow.h"

StackedWidget::StackedWidget(QWidget *parent) : QMainWindow(parent)
{
  this->qStackedWidget = new QStackedWidget();
  this->qStackedWidget->addWidget(new MainWindow(this));

  this->setCentralWidget(this->qStackedWidget);
}

void StackedWidget::previousView()
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
