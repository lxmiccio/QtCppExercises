#include "audiocontrols.h"

#include "imageloader.h"

AudioControls::AudioControls(QWidget *parent) : QWidget(parent)
{
  this->verticalLayout = new QVBoxLayout();

  this->upperHorizontalLayout = new QHBoxLayout();

  this->upperSpacer1 = new QSpacerItem(0, 0, QSizePolicy::Expanding);

  this->artist = new QLabel("Artist");

  this->dash = new QLabel(" - ");

  this->track = new QLabel("Track");

  this->upperSpacer2 = new QSpacerItem(0, 0, QSizePolicy::Expanding);

  this->upperHorizontalLayout->addItem(this->upperSpacer1);
  this->upperHorizontalLayout->addWidget(this->artist);
  this->upperHorizontalLayout->addWidget(this->dash);
  this->upperHorizontalLayout->addWidget(this->track);
  this->upperHorizontalLayout->addItem(this->upperSpacer2);

  this->lowerHorizontalLayout = new QHBoxLayout();

  this->fastBackward = new ImageButton(ImageLoader::pixmap(QString("images/fast_backward.svg"), QSize(15, 13), 1.0, Qt::black));
  this->fastBackward->setPixmap(ImageLoader::pixmap(QString("images/fast_backward.svg"), QSize(15, 13), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

  this->lowerSpacer1 = new QSpacerItem(12, 8, QSizePolicy::Fixed);

  this->backward = new ImageButton(ImageLoader::pixmap(QString("images/backward.svg"), QSize(15, 13), 1.0, Qt::black));
  this->backward->setPixmap(ImageLoader::pixmap(QString("images/backward.svg"), QSize(15, 13), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

  this->lowerSpacer2 = new QSpacerItem(24, 8, QSizePolicy::Fixed);

  this->play = new ImageButton(ImageLoader::pixmap(QString("images/play.svg"), QSize(15, 13), 1.0, Qt::black));
  this->play->setPixmap(ImageLoader::pixmap(QString("images/play.svg"), QSize(15, 13), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

  this->pause = new ImageButton(ImageLoader::pixmap(QString("images/pause.svg"), QSize(15, 13), 1.0, Qt::black));
  this->pause->setPixmap(ImageLoader::pixmap(QString("images/pause.svg"), QSize(15, 13), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

  this->lowerSpacer3 = new QSpacerItem(24, 8, QSizePolicy::Fixed);

  this->forward = new ImageButton(ImageLoader::pixmap(QString("images/forward.svg"), QSize(15, 13), 1.0, Qt::black));
  this->forward->setPixmap(ImageLoader::pixmap(QString("images/forward.svg"), QSize(15, 13), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

  this->lowerSpacer4 = new QSpacerItem(12, 8, QSizePolicy::Fixed);

  this->fastForward = new ImageButton(ImageLoader::pixmap(QString("images/fast_forward.svg"), QSize(15, 13), 1.0, Qt::black));
  this->fastForward->setPixmap(ImageLoader::pixmap(QString("images/fast_forward.svg"), QSize(15, 13), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

  this->lowerSpacer5 = new QSpacerItem(72, 8, QSizePolicy::Fixed);

  this->eslapsedTime = new QLabel("Eslapsed time");

  this->lowerSpacer6 = new QSpacerItem(12, 8, QSizePolicy::Fixed);

  this->musicSlider = new QSlider(Qt::Horizontal);
  this->musicSlider->setMinimumWidth(240);
  this->musicSlider->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);

  this->lowerSpacer7 = new QSpacerItem(12, 8, QSizePolicy::Fixed);

  this->remainingTime = new QLabel("Remaining time");

  this->lowerSpacer8 = new QSpacerItem(72, 8, QSizePolicy::Fixed);

  this->shuffle = new ImageButton(ImageLoader::pixmap(QString("images/shuffle.svg"), QSize(15, 13), 1.0, Qt::black));
  this->shuffle->setPixmap(ImageLoader::pixmap(QString("images/shuffle.svg"), QSize(15, 13), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

  this->lowerSpacer9 = new QSpacerItem(24, 8, QSizePolicy::Fixed);

  this->repeat = new ImageButton(ImageLoader::pixmap(QString("images/repeat.svg"), QSize(15, 13), 1.0, Qt::black));
  this->repeat->setPixmap(ImageLoader::pixmap(QString("images/repeat.svg"), QSize(15, 13), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

  this->lowerSpacer10 = new QSpacerItem(24, 8, QSizePolicy::Fixed);

  this->volume = new ImageButton(ImageLoader::pixmap(QString("images/volume.svg"), QSize(15, 13), 1.0, Qt::black));
  this->volume->setPixmap(ImageLoader::pixmap(QString("images/volume.svg"), QSize(15, 13), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

  this->volumeSlider = new QSlider(Qt::Horizontal);
  this->volumeSlider->setMinimumWidth(120);
  this->volumeSlider->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

  this->lowerHorizontalLayout->addWidget(this->fastBackward);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer1);
  this->lowerHorizontalLayout->addWidget(this->backward);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer2);
  this->lowerHorizontalLayout->addWidget(this->play);
  this->lowerHorizontalLayout->addWidget(this->pause);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer3);
  this->lowerHorizontalLayout->addWidget(this->forward);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer4);
  this->lowerHorizontalLayout->addWidget(this->fastForward);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer5);
  this->lowerHorizontalLayout->addWidget(this->eslapsedTime);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer6);
  this->lowerHorizontalLayout->addWidget(this->musicSlider);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer7);
  this->lowerHorizontalLayout->addWidget(this->remainingTime);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer8);
  this->lowerHorizontalLayout->addWidget(this->shuffle);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer9);
  this->lowerHorizontalLayout->addWidget(this->repeat);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer10);
  this->lowerHorizontalLayout->addWidget(this->volume);
  this->lowerHorizontalLayout->addWidget(this->volumeSlider);

  this->verticalLayout->addLayout(this->upperHorizontalLayout);
  this->verticalLayout->addLayout(this->lowerHorizontalLayout);

  this->setLayout(this->verticalLayout);
}
