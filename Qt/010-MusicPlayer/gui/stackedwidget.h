#ifndef STACKWIDGET_H
#define STACKWIDGET_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QWidget>

class StackedWidget : public QMainWindow
{
  Q_OBJECT

  protected:
    QStackedWidget* qStackedWidget;

  public:
    explicit StackedWidget(QWidget* parent = 0);

    QStackedWidget* getQStackedWidget() { return this->qStackedWidget; }

  public slots:
    void previousView();
};

#endif // STACKWIDGET_H
