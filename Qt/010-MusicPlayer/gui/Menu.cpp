#include "Menu.h"

#include "ImageUtils.h"

Menu::Menu(QWidget* parent) : QWidget(parent)
{
    m_previousPage = new ImageButton();
    m_previousPage->setPixmap(ImageUtils::pixmap(QString(":/svg/backward.svg"), QSize(17, 17), 1.0, Qt::gray));
    m_previousPage->setPixmap(ImageUtils::pixmap(QString(":/svg/backward.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);

    m_spacer1 = new QSpacerItem(36, 0, QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_nextPage = new ImageButton();
    m_nextPage->setPixmap(ImageUtils::pixmap(QString(":/svg/forward.svg"), QSize(17, 17), 1.0, Qt::gray));
    m_nextPage->setPixmap(ImageUtils::pixmap(QString(":/svg/forward.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);

    m_spacer2 = new QSpacerItem(36, 0, QSizePolicy::Expanding, QSizePolicy::Fixed);

    m_layout = new QHBoxLayout();
    m_layout->setContentsMargins(40, 16, 40, 12);
    m_layout->addWidget(m_previousPage);
    m_layout->addItem(m_spacer1);
    m_layout->addWidget(m_nextPage);
    m_layout->addItem(m_spacer2);

    setLayout(m_layout);

    setFixedHeight(45);
}

Menu::~Menu()
{

}
