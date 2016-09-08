#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QLabel>
#include <QPushButton>

#include <basewidget.h>
#include <stackedwidget.h>

class MainWidget : public BaseWidget
{
    Q_OBJECT

protected:
    QLabel* message;
    QPushButton* button1;
    QPushButton* button2;

public:
    explicit MainWidget(StackedWidget* stackedWidget, QWidget* parent = 0);

public slots:
    void createFirstWidget();
    void createSecondWidget();
};

#endif // MAINWIDGET_H
