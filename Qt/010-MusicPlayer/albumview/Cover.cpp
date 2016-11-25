#include "Cover.h"

Cover::Cover(const Album* album, QWidget* parent) : QWidget(parent)
{
    c_album = album;

    QPixmap pixmap(QPixmap::fromImage(c_album->getImage().scaled(Cover::COVER_WIDTH, Cover::COVER_HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation)));

    m_cover = new ClickableLabel();
    m_cover->setPixmap(pixmap);

    m_albumTitle = new ElidedLabel(album->title());
    m_albumTitle->setAlignment(Qt::AlignCenter);

    m_artistName = new ElidedLabel(album->artist()->name());
    m_artistName->setAlignment(Qt::AlignCenter);

    QObject::connect(m_cover, SIGNAL(clicked()), this, SLOT(onCoverClicked()));
    QObject::connect(m_albumTitle, SIGNAL(clicked()), this, SLOT(onCoverClicked()));
    QObject::connect(m_artistName, SIGNAL(clicked()), this, SLOT(onCoverClicked()));

    m_layout = new QVBoxLayout();
    m_layout->setMargin(0);
    m_layout->addWidget(m_cover);
    m_layout->addWidget(m_albumTitle);
    m_layout->addWidget(m_artistName);
    setLayout(m_layout);

    setFixedSize(Cover::COVER_WIDTH, Cover::COVER_HEIGHT);
}

Cover::~Cover()
{
    delete m_cover;
    delete m_albumTitle;
    delete m_artistName;
    delete m_layout;
}

const Album& Cover::album() const
{
    return *c_album;
}

void Cover::onCoverClicked()
{
    emit coverClicked(*c_album);
}
