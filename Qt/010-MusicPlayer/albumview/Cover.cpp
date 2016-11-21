#include "Cover.h"

Cover::Cover(Album* album, QWidget* parent) : QWidget(parent)
{
  m_album = album;

  m_cover = new ClickableLabel();
  m_cover->setPixmap(QPixmap::fromImage(m_album->getImage().scaled(Cover::COVER_WIDTH, Cover::COVER_HEIGHT, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
  QObject::connect(m_cover, SIGNAL(clicked()), this, SLOT(onClicked()));

  m_albumTitle = new ElidedLabel(album->getTitle());
  m_albumTitle->setAlignment(Qt::AlignCenter);
  QObject::connect(m_albumTitle, SIGNAL(clicked()), this, SLOT(onClicked()));

  m_artistName = new ElidedLabel(album->getArtist()->getName());
  m_artistName->setAlignment(Qt::AlignCenter);
  QObject::connect(m_artistName, SIGNAL(clicked()), this, SLOT(onClicked()));

  m_layout = new QVBoxLayout();
  m_layout->addWidget(m_cover);
  m_layout->addWidget(m_albumTitle);
  m_layout->addWidget(m_artistName);
  m_layout->setMargin(0);

  setFixedSize(Cover::COVER_WIDTH, Cover::COVER_HEIGHT);
  setLayout(m_layout);
}

Cover::~Cover()
{
  delete m_cover;
  delete m_albumTitle;
  delete m_artistName;
  delete m_layout;
}

Album* Cover::album() const
{
  return m_album;
}

void Cover::onClicked()
{
  emit clicked(*m_album);
}
