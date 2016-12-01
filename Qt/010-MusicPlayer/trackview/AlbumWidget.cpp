#include "AlbumWidget.h"

#include "Cover.h"

#include <QDebug>

AlbumWidget::AlbumWidget(QWidget* parent) : QWidget(parent)
{
    m_cover = new QLabel();
    m_cover->setPixmap(QPixmap());

    m_spacer1 = new QSpacerItem(8, 24, QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_albumTitle = new ElidedLabel();
    m_albumTitle->setAlignment(Qt::AlignCenter);
    m_albumTitle->setStyleSheet(QString("color: white;"));

    m_spacer2 = new QSpacerItem(8, 24, QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_artistName = new ElidedLabel();
    m_artistName->setAlignment(Qt::AlignCenter);
    m_artistName->setStyleSheet(QString("color: white;"));

    m_spacer3 = new QSpacerItem(8, 24, QSizePolicy::Fixed, QSizePolicy::Expanding);

    m_layout = new QVBoxLayout();
    m_layout->setMargin(0);
    m_layout->addWidget(m_cover);
    m_layout->addItem(m_spacer1);
    m_layout->addWidget(m_albumTitle);
    m_layout->addItem(m_spacer2);
    m_layout->addWidget(m_artistName);
    m_layout->addItem(m_spacer3);
    setLayout(m_layout);
}

void AlbumWidget::setAlbum(const Album *album)
{
    c_album = album;

    QPixmap pixmap(QPixmap::fromImage(c_album->getImage().scaled(Cover::COVER_WIDTH, Cover::COVER_HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation)));

    m_albumTitle->setText(album->title());
    m_artistName->setText(album->artist()->name());
    m_cover->setPixmap(pixmap);
}
