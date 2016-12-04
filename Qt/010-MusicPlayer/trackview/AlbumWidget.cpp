#include "AlbumWidget.h"

#include "Cover.h"

AlbumWidget::AlbumWidget(QWidget* parent) : QWidget(parent)
{
    m_cover = new QLabel();
    m_cover->setAlignment(Qt::AlignCenter);
    m_cover->setPixmap(QPixmap());

    m_spacer1 = new QSpacerItem(0, 16, QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_albumTitle = new QLabel();
    m_albumTitle->setAlignment(Qt::AlignCenter);
    m_albumTitle->setWordWrap(true);
    m_albumTitle->setStyleSheet(QString("color: white;"));

    m_spacer2 = new QSpacerItem(0, 16, QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_artistName = new QLabel();
    m_artistName->setAlignment(Qt::AlignCenter);
    m_artistName->setWordWrap(true);
    m_artistName->setStyleSheet(QString("color: white;"));

    m_spacer3 = new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Expanding);

    m_layout = new QVBoxLayout();
    m_layout->setMargin(0);
    m_layout->setSpacing(0);
    m_layout->addWidget(m_cover);
    m_layout->addItem(m_spacer1);
    m_layout->addWidget(m_albumTitle);
    m_layout->addItem(m_spacer2);
    m_layout->addWidget(m_artistName);
    m_layout->addItem(m_spacer3);
    setLayout(m_layout);

    setMinimumHeight(AlbumWidget::WIDGET_HEIGHT);
    setFixedWidth(AlbumWidget::WIDGET_WIDTH);
}

AlbumWidget::~AlbumWidget()
{
    /*
    delete m_cover;
    delete m_spacer1;
    delete m_albumTitle;
    delete m_spacer2;
    delete m_artistName;
    delete m_spacer3;
    delete m_layout;
    */
}

void AlbumWidget::setAlbum(const Album *album)
{
    c_album = album;

    m_albumTitle->setText(album->title());
    m_artistName->setText(album->artist()->name());
    m_cover->setPixmap(QPixmap::fromImage(c_album->image().scaled(AlbumWidget::IMAGE_WIDTH, AlbumWidget::IMAGE_HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
}
