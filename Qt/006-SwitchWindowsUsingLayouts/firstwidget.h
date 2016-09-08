#ifndef FIRSTWIDGET_H
#define FIRSTWIDGET_H

#include <QAction>
#include <QLabel>
#include <QPushButton>

#include "basewidget.h"

class FirstWidget : public BaseWidget
{
    Q_OBJECT

protected:
    QLabel* message;
    QPushButton* button2;
    QAction* secondWindowAction;

public:
    explicit FirstWidget(QStackedWidget* stackedWidget, QWidget *parent = 0);

public slots:
    void createSecondWidget();
};

#endif // FIRSTWIDGET_H
