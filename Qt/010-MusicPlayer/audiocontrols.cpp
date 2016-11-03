#include "audiocontrols.h"

#include "imageloader.h"

AC::AudioControls::AudioControls(QWidget* parent) : QWidget(parent)
{
  this->upperSpacer1 = new QSpacerItem(0, 0, QSizePolicy::Expanding);

  this->artist = new QLabel("Artist");

  this->dash = new QLabel("-");

  this->track = new QLabel("Track");

  this->upperSpacer2 = new QSpacerItem(0, 0, QSizePolicy::Expanding);

  this->upperHorizontalLayout = new QHBoxLayout();
  this->upperHorizontalLayout->addItem(this->upperSpacer1);
  this->upperHorizontalLayout->addWidget(this->artist);
  this->upperHorizontalLayout->addWidget(this->dash);
  this->upperHorizontalLayout->addWidget(this->track);
  this->upperHorizontalLayout->addItem(this->upperSpacer2);

  this->fastBackward = new ImageButton();
  this->fastBackward->setPixmap(ImageLoader::pixmap(QString("images/fast_backward.svg"), QSize(20, 20), 1.0, Qt::black));
  this->fastBackward->setPixmap(ImageLoader::pixmap(QString("images/fast_backward.svg"), QSize(20, 20), 1.0, Qt::red), QIcon::Off, QIcon::Active);
  QObject::connect(this->fastBackward, SIGNAL(clicked()), this, SLOT(onFastBackwardClicked()));

  this->lowerSpacer1 = new QSpacerItem(12, 8, QSizePolicy::Fixed);

  this->backward = new ImageButton();
  this->backward->setPixmap(ImageLoader::pixmap(QString("images/backward.svg"), QSize(20, 20), 1.0, Qt::black));
  this->backward->setPixmap(ImageLoader::pixmap(QString("images/backward.svg"), QSize(20, 20), 1.0, Qt::gray), QIcon::Off, QIcon::Active);
  QObject::connect(this->backward, SIGNAL(clicked()), this, SLOT(onBackwardClicked()));

  this->lowerSpacer2 = new QSpacerItem(24, 8, QSizePolicy::Fixed);

  this->play = new ImageButton();
  this->play->setPixmap(ImageLoader::pixmap(QString("images/play.svg"), QSize(20, 20), 1.0, Qt::black));
  this->play->setPixmap(ImageLoader::pixmap(QString("images/play.svg"), QSize(20, 20), 1.0, Qt::gray), QIcon::Off, QIcon::Active);
  QObject::connect(this->play, SIGNAL(clicked()), this, SLOT(onPlayClicked()));

  this->pause = new ImageButton();
  this->pause->setPixmap(ImageLoader::pixmap(QString("images/pause.svg"), QSize(20, 20), 1.0, Qt::black));
  this->pause->setPixmap(ImageLoader::pixmap(QString("images/pause.svg"), QSize(20, 20), 1.0, Qt::gray), QIcon::Off, QIcon::Active);
  this->pause->hide();
  QObject::connect(this->pause, SIGNAL(clicked()), this, SLOT(onPauseClicked()));

  this->lowerSpacer3 = new QSpacerItem(24, 8, QSizePolicy::Fixed);

  this->forward = new ImageButton();
  this->forward->setPixmap(ImageLoader::pixmap(QString("images/forward.svg"), QSize(20, 20), 1.0, Qt::black));
  this->forward->setPixmap(ImageLoader::pixmap(QString("images/forward.svg"), QSize(20, 20), 1.0, Qt::gray), QIcon::Off, QIcon::Active);
  QObject::connect(this->forward, SIGNAL(clicked()), this, SLOT(onForwardClicked()));

  this->lowerSpacer4 = new QSpacerItem(12, 8, QSizePolicy::Fixed);

  this->fastForward = new ImageButton();
  this->fastForward->setPixmap(ImageLoader::pixmap(QString("images/fast_forward.svg"), QSize(20, 20), 1.0, Qt::black));
  this->fastForward->setPixmap(ImageLoader::pixmap(QString("images/fast_forward.svg"), QSize(20, 20), 1.0, Qt::gray), QIcon::Off, QIcon::Active);
  QObject::connect(this->fastForward, SIGNAL(clicked()), this, SLOT(onFastForwardClicked()));

  this->lowerSpacer5 = new QSpacerItem(144, 8, QSizePolicy::Fixed);

  this->eslapsedTime = new QLabel("Eslapsed time");

  this->lowerSpacer6 = new QSpacerItem(12, 8, QSizePolicy::Fixed);

  this->musicSlider = new QSlider(Qt::Horizontal);
  this->musicSlider->setMinimumWidth(240);
  this->musicSlider->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
  QObject::connect(this->musicSlider, SIGNAL(sliderMoved(int)), this, SLOT(onMusicSliderMoved(int)));

  this->lowerSpacer7 = new QSpacerItem(12, 8, QSizePolicy::Fixed);

  this->remainingTime = new QLabel("Remaining time");

  this->lowerSpacer8 = new QSpacerItem(72, 8, QSizePolicy::Fixed);

  this->shuffle = new ImageButton();
  this->shuffle->setPixmap(ImageLoader::pixmap(QString("images/shuffle.svg"), QSize(20, 20), 1.0, Qt::black));
  this->shuffle->setPixmap(ImageLoader::pixmap(QString("images/shuffle.svg"), QSize(20, 20), 1.0, Qt::gray), QIcon::Off, QIcon::Active);
  QObject::connect(this->shuffle, SIGNAL(clicked()), this, SLOT(onShuffleClicked()));

  this->lowerSpacer9 = new QSpacerItem(24, 8, QSizePolicy::Fixed);

  this->repeat = new ImageButton();
  this->repeat->setPixmap(ImageLoader::pixmap(QString("images/repeat.svg"), QSize(20, 20), 1.0, Qt::black));
  this->repeat->setPixmap(ImageLoader::pixmap(QString("images/repeat.svg"), QSize(20, 20), 1.0, Qt::gray), QIcon::Off, QIcon::Active);
  QObject::connect(this->repeat, SIGNAL(clicked()), this, SLOT(onRepeatClicked()));

  this->lowerSpacer10 = new QSpacerItem(24, 8, QSizePolicy::Fixed);

  this->volume = new ImageButton();
  this->volume->setPixmap(ImageLoader::pixmap(QString("images/volume.svg"), QSize(20, 20), 1.0, Qt::black));
  this->volume->setPixmap(ImageLoader::pixmap(QString("images/volume.svg"), QSize(20, 20), 1.0, Qt::gray), QIcon::Off, QIcon::Active);
  QObject::connect(this->volume, SIGNAL(clicked()), this, SLOT(onVolumeClicked()));

  this->volumeSlider = new QSlider(Qt::Horizontal);
  this->volumeSlider->setMinimumWidth(120);
  this->volumeSlider->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  QObject::connect(this->volumeSlider, SIGNAL(sliderMoved(int)), this, SLOT(onVolumeSliderMoved(int)));

  this->lowerHorizontalLayout = new QHBoxLayout();
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

  this->verticalLayout = new QVBoxLayout();
  this->verticalLayout->addLayout(this->upperHorizontalLayout);
  this->verticalLayout->addLayout(this->lowerHorizontalLayout);

  this->setLayout(this->verticalLayout);

  this->repeatMode = AC::REPEAT_NONE;
  this->shuffleMode = AC::SHUFFLE_OFF;
  this->volumeMode = AC::VOLUME_NOT_MUTED;
}

void AC::AudioControls::onMediaChanged(Track& track)
{
  this->artist->setText(track.getArtist());
  this->track->setText(track.getTitle());
}

void AC::AudioControls::onFastBackwardClicked()
{
  emit this->fastBackwardClicked();
}

void AC::AudioControls::onBackwardClicked()
{
  emit this->backwardClicked();
}

void AC::AudioControls::onPlayClicked()
{
  this->play->hide();
  this->pause->show();

  emit this->playClicked();
}

void AC::AudioControls::onPauseClicked()
{
  this->pause->hide();
  this->play->show();

  emit this->pauseClicked();
}

void AC::AudioControls::onForwardClicked()
{
  emit this->forwardClicked();
}

void AC::AudioControls::onFastForwardClicked()
{
  emit this->fastForwardClicked();
}

void AC::AudioControls::onMusicSliderMoved(int position)
{
  emit this->musicSliderMoved(position);
}

void AC::AudioControls::onShuffleClicked()
{
  switch (this->shuffleMode)
  {
    case AC::SHUFFLE_OFF: {
      this->shuffle->setPixmap(ImageLoader::pixmap(QString("images/shuffle.svg"), QSize(20, 20), 1.0, Qt::blue));
      this->shuffle->setPixmap(ImageLoader::pixmap(QString("images/shuffle.svg"), QSize(20, 20), 0.5, Qt::blue), QIcon::Off, QIcon::Active);

      this->shuffleMode = AC::SHUFFLE_ON;
      break;
    }

    case AC::SHUFFLE_ON: {
      this->shuffle->setPixmap(ImageLoader::pixmap(QString("images/shuffle.svg"), QSize(20, 20), 1.0, Qt::black));
      this->shuffle->setPixmap(ImageLoader::pixmap(QString("images/shuffle.svg"), QSize(20, 20), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

      this->shuffleMode = AC::SHUFFLE_OFF;
      break;
    }

    default: {
      break;
    }
  }

  emit this->shuffleClicked(this->shuffleMode);
}

void AC::AudioControls::onRepeatClicked()
{
  switch (this->repeatMode)
  {
    case AC::REPEAT_NONE: {
      this->repeat->setPixmap(ImageLoader::pixmap(QString("images/repeat_one.svg"), QSize(20, 20), 1.0, Qt::black));
      this->repeat->setPixmap(ImageLoader::pixmap(QString("images/repeat_one.svg"), QSize(20, 20), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

      this->repeatMode = AC::REPEAT_ONE;
      break;
    }

    case AC::REPEAT_ONE: {
      this->repeat->setPixmap(ImageLoader::pixmap(QString("images/repeat_all.svg"), QSize(20, 20), 1.0, Qt::black));
      this->repeat->setPixmap(ImageLoader::pixmap(QString("images/repeat_all.svg"), QSize(20, 20), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

      this->repeatMode = AC::REPEAT_ALL;
      break;
    }

    case AC::REPEAT_ALL: {
      this->repeat->setPixmap(ImageLoader::pixmap(QString("images/repeat.svg"), QSize(20, 20), 1.0, Qt::black));
      this->repeat->setPixmap(ImageLoader::pixmap(QString("images/repeat.svg"), QSize(20, 20), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

      this->repeatMode = AC::REPEAT_NONE;
      break;
    }

    default: {
      break;
    }
  }

  emit this->repeatClicked(this->repeatMode);
}

void AC::AudioControls::onVolumeClicked()
{
  switch (this->volumeMode)
  {
    case AC::VOLUME_MUTED: {
      this->volume->setPixmap(ImageLoader::pixmap(QString("images/volume.svg"), QSize(20, 20), 1.0, Qt::black));
      this->volume->setPixmap(ImageLoader::pixmap(QString("images/volume.svg"), QSize(20, 20), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

      this->volumeMode = AC::VOLUME_NOT_MUTED;
      break;
    }

    case AC::VOLUME_NOT_MUTED: {
      this->volume->setPixmap(ImageLoader::pixmap(QString("images/volume_muted.svg"), QSize(20, 20), 1.0, Qt::black));
      this->volume->setPixmap(ImageLoader::pixmap(QString("images/volume_muted.svg"), QSize(20, 20), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

      this->volumeMode = AC::VOLUME_MUTED;
      break;
    }

    default: {
      break;
    }
  }

  emit this->volumeClicked(this->volumeMode);
}

void AC::AudioControls::onVolumeSliderMoved(int position)
{
  emit this->volumeSliderMoved(position);
}
