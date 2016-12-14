#ifndef MENU_H
#define MENU_H

#include <QHBoxLayout>
#include <QWidget>

#include "ImageButton.h"

class Menu : public QWidget
{
    public:
        explicit Menu(QWidget* parent = 0);
        ~Menu();

    private:
        ImageButton* m_previousPage;
        QSpacerItem* m_spacer1;
        ImageButton* m_nextPage;
        QSpacerItem* m_spacer2;

        QHBoxLayout* m_layout;
};

#endif // MENU_H
