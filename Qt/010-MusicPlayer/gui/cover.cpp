#include "cover.h"

Cover::Cover(const Album *album, QWidget *parent) : QWidget(parent)
{
  this->album = album;

  QImage image("images/qoct.jpg");

  this->cover = new ImageButton();
  this->cover->setPixmap(QPixmap::fromImage(image.scaled(175, 175, Qt::KeepAspectRatio, Qt::SmoothTransformation)));

  this->lblAlbum = new ElidedLabel(album->getTitle());
  this->lblAlbum->setAlignment(Qt::AlignCenter);

  this->lblArtist = new ElidedLabel(album->getArtist()->getName());
  this->lblArtist->setAlignment(Qt::AlignCenter);

  QVBoxLayout* verticalLayout = new QVBoxLayout();
  verticalLayout->setMargin(0);
  verticalLayout->addWidget(this->cover);
  verticalLayout->addWidget(this->lblAlbum);
  verticalLayout->addWidget(this->lblArtist);

  this->setLayout(verticalLayout);

  this->setFixedSize(175, 200);
}
