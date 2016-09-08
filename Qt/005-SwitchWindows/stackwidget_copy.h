#ifndef STACKWIDGET_H
#define STACKWIDGET_H

#include <QMainWindow>
#include <QStackedWidget>

class StackWidget : public QMainWindow
{
    Q_OBJECT

public:
    QStackedWidget *stackedWidget;

public:
    explicit StackWidget(QWidget *parent = 0);

public slots:
    void widgetChanged(int index);
};

#endif // STACKWIDGET_H
