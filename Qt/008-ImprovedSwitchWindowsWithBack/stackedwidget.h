#ifndef STACKWIDGET_H
#define STACKWIDGET_H

#include <QMainWindow>
#include <QStackedWidget>

class StackedWidget : public QMainWindow
{
    Q_OBJECT

protected:
    QStackedWidget *qStackedWidget;

public:
    explicit StackedWidget(QWidget* parent = 0);

    QStackedWidget* getQStackedWidget() { return this->qStackedWidget; }

public slots:
    void goToNewWidget(int index);
    void returnToMainWidget();
    void returnToPreviousWidget();
};

#endif // STACKWIDGET_H
