#include "AudioControls.h"

#include <QFontDatabase>

#include "ImageUtils.h"

AudioControls::AudioControls(QWidget* parent) : BackgroundWidget(parent)
{
  QImage i(":/images/tove-lo.jpg");
  this->setBackgroundImage(QPixmap::fromImage(ImageUtils::blur(i, i.rect(), 30, false, true)));

  QFont font = this->font();
  font.setBold(true);
  font.setFamily("Roboto Condensed");
  font.setPointSize(13);

  this->upperSpacer1 = new QSpacerItem(0, 0, QSizePolicy::Expanding);

  this->artist = new QLabel("WTF Love Is");
  this->artist->setFont(font);
  this->artist->setStyleSheet(QString("color: white;"));

  this->dash = new QLabel("-");
  this->dash->setFont(font);
  this->dash->setStyleSheet(QString("color: white;"));

  this->track = new QLabel("Tove Lo");
  this->track->setFont(font);
  this->track->setStyleSheet(QString("color: white;"));

  this->upperSpacer2 = new QSpacerItem(0, 0, QSizePolicy::Expanding);

  this->upperHorizontalLayout = new QHBoxLayout();
  this->upperHorizontalLayout->addItem(this->upperSpacer1);
  this->upperHorizontalLayout->addWidget(this->artist);
  this->upperHorizontalLayout->addWidget(this->dash);
  this->upperHorizontalLayout->addWidget(this->track);
  this->upperHorizontalLayout->addItem(this->upperSpacer2);

  this->lowerSpacer1 = new QSpacerItem(24, 8, QSizePolicy::Fixed);

  this->fastBackward = new ImageButton();
  this->fastBackward->setPixmap(ImageUtils::pixmap(QString("images/fast_backward.svg"), QSize(17, 17), 1.0, Qt::gray));
  this->fastBackward->setPixmap(ImageUtils::pixmap(QString("images/fast_backward.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);
  QObject::connect(this->fastBackward, SIGNAL(clicked()), this, SLOT(onFastBackwardClicked()));

  this->lowerSpacer2 = new QSpacerItem(16, 8, QSizePolicy::Fixed);

  this->backward = new ImageButton();
  this->backward->setPixmap(ImageUtils::pixmap(QString(":/svg/backward.svg"), QSize(17, 17), 1.0, Qt::gray));
  this->backward->setPixmap(ImageUtils::pixmap(QString(":/svg/backward.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);
  QObject::connect(this->backward, SIGNAL(clicked()), this, SLOT(onBackwardClicked()));

  this->lowerSpacer3 = new QSpacerItem(16, 8, QSizePolicy::Fixed);

  this->play = new ImageButton();
  this->play->setPixmap(ImageUtils::pixmap(QString(":/svg/play.svg"), QSize(17, 17), 1.0, Qt::gray));
  this->play->setPixmap(ImageUtils::pixmap(QString(":/svg/play.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);
  QObject::connect(this->play, SIGNAL(clicked()), this, SLOT(onPlayClicked()));

  this->pause = new ImageButton();
  this->pause->setPixmap(ImageUtils::pixmap(QString(":/svg/pause.svg"), QSize(17, 17), 1.0, Qt::gray));
  this->pause->setPixmap(ImageUtils::pixmap(QString(":/svg/pause.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);
  this->pause->hide();
  QObject::connect(this->pause, SIGNAL(clicked()), this, SLOT(onPauseClicked()));

  this->lowerSpacer4 = new QSpacerItem(16, 8, QSizePolicy::Fixed);

  this->forward = new ImageButton();
  this->forward->setPixmap(ImageUtils::pixmap(QString(":/svg/forward.svg"), QSize(17, 17), 1.0, Qt::gray));
  this->forward->setPixmap(ImageUtils::pixmap(QString(":/svg/forward.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);
  QObject::connect(this->forward, SIGNAL(clicked()), this, SLOT(onForwardClicked()));

  this->lowerSpacer5 = new QSpacerItem(16, 8, QSizePolicy::Fixed);

  this->fastForward = new ImageButton();
  this->fastForward->setPixmap(ImageUtils::pixmap(QString("images/fast_forward.svg"), QSize(17, 17), 1.0, Qt::gray));
  this->fastForward->setPixmap(ImageUtils::pixmap(QString("images/fast_forward.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);
  QObject::connect(this->fastForward, SIGNAL(clicked()), this, SLOT(onFastForwardClicked()));

  this->lowerSpacer6 = new QSpacerItem(120, 8, QSizePolicy::Fixed);

  font.setBold(true);
  font.setPointSize(10);

  this->eslapsedTime = new QLabel("00:00");
  this->eslapsedTime->setFont(font);
  this->eslapsedTime->setStyleSheet(QString("color: white; margin-top: -2px;"));

  this->lowerSpacer7 = new QSpacerItem(6, 8, QSizePolicy::Fixed);

  this->musicSlider = new SeekSlider(Qt::Horizontal);
  this->musicSlider->setFixedHeight(6);
  this->musicSlider->setMinimumWidth(256);

  this->musicSlider->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
  QObject::connect(this->musicSlider, SIGNAL(sliderMoved(int)), this, SLOT(onMusicSliderMoved(int)));

  this->lowerSpacer8 = new QSpacerItem(6, 8, QSizePolicy::Fixed);

  this->remainingTime = new QLabel("00:00");
  this->remainingTime->setFont(font);
  this->remainingTime->setStyleSheet(QString("color: white; margin-top: -2px;"));

  this->lowerSpacer9 = new QSpacerItem(36, 8, QSizePolicy::Fixed);

  this->shuffle = new ImageButton();
  this->shuffle->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  this->shuffle->setPixmap(ImageUtils::pixmap(QString(":/svg/shuffle.svg"), QSize(17, 17), 1.0, Qt::gray));
  this->shuffle->setPixmap(ImageUtils::pixmap(QString(":/svg/shuffle.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);
  QObject::connect(this->shuffle, SIGNAL(clicked()), this, SLOT(onShuffleClicked()));

  this->lowerSpacer10 = new QSpacerItem(36, 8, QSizePolicy::Fixed);

  this->repeat = new ImageButton();
  this->repeat->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  this->repeat->setPixmap(ImageUtils::pixmap(QString(":/svg/repeat.svg"), QSize(17, 17), 1.0, Qt::gray));
  this->repeat->setPixmap(ImageUtils::pixmap(QString(":/svg/repeat.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);
  QObject::connect(this->repeat, SIGNAL(clicked()), this, SLOT(onRepeatClicked()));

  this->lowerSpacer11 = new QSpacerItem(36, 8, QSizePolicy::Fixed);

  this->volume = new ImageButton();
  this->volume->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  this->volume->setPixmap(ImageUtils::pixmap(QString(":/svg/volume.svg"), QSize(17, 17), 1.0, Qt::white));
  this->volume->setPixmap(ImageUtils::pixmap(QString(":/svg/volume.svg"), QSize(17, 17), 1.0, Qt::gray), QIcon::Off, QIcon::Active);
  QObject::connect(this->volume, SIGNAL(clicked()), this, SLOT(onVolumeClicked()));

  this->volumeSlider = new SeekSlider(Qt::Horizontal);
  this->volumeSlider->setFixedHeight(6);
  this->volumeSlider->setMinimumWidth(120);
  this->volumeSlider->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  QObject::connect(this->volumeSlider, SIGNAL(sliderMoved(int)), this, SLOT(onVolumeSliderMoved(int)));

  this->lowerSpacer12 = new QSpacerItem(24, 8, QSizePolicy::Fixed);

  this->lowerHorizontalLayout = new QHBoxLayout();
  this->lowerHorizontalLayout->addItem(this->lowerSpacer1);
  //this->lowerHorizontalLayout->addWidget(this->fastBackward);
  //this->lowerHorizontalLayout->addItem(this->lowerSpacer2);
  this->lowerHorizontalLayout->addWidget(this->backward);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer3);
  this->lowerHorizontalLayout->addWidget(this->play);
  this->lowerHorizontalLayout->addWidget(this->pause);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer4);
  this->lowerHorizontalLayout->addWidget(this->forward);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer5);
  //this->lowerHorizontalLayout->addWidget(this->fastForward);
  //this->lowerHorizontalLayout->addItem(this->lowerSpacer6);
  this->lowerHorizontalLayout->addWidget(this->eslapsedTime);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer7);
  this->lowerHorizontalLayout->addWidget(this->musicSlider);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer8);
  this->lowerHorizontalLayout->addWidget(this->remainingTime);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer9);
  this->lowerHorizontalLayout->addWidget(this->shuffle);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer10);
  this->lowerHorizontalLayout->addWidget(this->repeat);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer11);
  this->lowerHorizontalLayout->addWidget(this->volume);
  this->lowerHorizontalLayout->addWidget(this->volumeSlider);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer12);

  this->verticalLayout = new QVBoxLayout();
  this->verticalLayout->setMargin(16);
  this->verticalLayout->setSpacing(8);
  this->verticalLayout->addLayout(this->upperHorizontalLayout);
  this->verticalLayout->addLayout(this->lowerHorizontalLayout);

  this->setLayout(this->verticalLayout);

  this->repeatMode = AC::REPEAT_NONE;
  this->shuffleMode = AC::SHUFFLE_OFF;
  this->volumeMode = AC::VOLUME_NOT_MUTED;
}

void AudioControls::showPlay(bool show)
{
  show ? this->play->show() : this->play->hide();
}

void AudioControls::showPause(bool show)
{
  show ? this->pause->show() : this->pause->hide();
}

void AudioControls::onCurrentMediaChanged(Track& track)
{
  //this->artist->setText(track.getArtist());
  //this->track->setText(track.getTitle());
}

void AudioControls::onPositionChanged(qint64 position, qint64 duration)
{
  if(duration != 0) {
    this->musicSlider->setValue((this->musicSlider->maximum() - this->musicSlider->minimum()) * position / duration);
  }
}

void AudioControls::onFastBackwardClicked()
{
  emit this->fastBackwardClicked();
}

void AudioControls::onBackwardClicked()
{
  emit this->backwardClicked();
}

void AudioControls::onPlayClicked()
{
  this->play->hide();
  this->pause->show();

  emit this->playClicked();
}

void AudioControls::onPauseClicked()
{
  this->pause->hide();
  this->play->show();

  emit this->pauseClicked();
}

void AudioControls::onForwardClicked()
{
  emit this->forwardClicked();
}

void AudioControls::onFastForwardClicked()
{
  emit this->fastForwardClicked();
}

void AudioControls::onMusicSliderMoved(int position)
{
  emit this->musicSliderMoved(position, this->musicSlider->minimum(), this->musicSlider->maximum());
}

void AudioControls::onShuffleClicked()
{
  switch (this->shuffleMode)
  {
  case AC::SHUFFLE_OFF: {
    this->shuffle->setPixmap(ImageUtils::pixmap(QString(":/svg/shuffle.svg"), QSize(17, 17), 1.0, Qt::white));
    this->shuffle->setPixmap(ImageUtils::pixmap(QString(":/svg/shuffle.svg"), QSize(17, 17), 0.5, Qt::gray), QIcon::Off, QIcon::Active);

    this->shuffleMode = AC::SHUFFLE_ON;
    break;
  }

  case AC::SHUFFLE_ON: {
    this->shuffle->setPixmap(ImageUtils::pixmap(QString(":/svg/shuffle.svg"), QSize(17, 17), 1.0, Qt::gray));
    this->shuffle->setPixmap(ImageUtils::pixmap(QString(":/svg/shuffle.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);

    this->shuffleMode = AC::SHUFFLE_OFF;
    break;
  }

  default: {
    break;
  }
  }

  emit this->shuffleClicked(this->shuffleMode);
}

void AudioControls::onRepeatClicked()
{
  switch (this->repeatMode)
  {
  case AC::REPEAT_NONE: {
    this->repeat->setPixmap(ImageUtils::pixmap(QString(":/svg/repeat_one.svg"), QSize(17, 17), 1.0, Qt::white));
    this->repeat->setPixmap(ImageUtils::pixmap(QString(":/svg/repeat_one.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);

    this->repeatMode = AC::REPEAT_ONE;
    break;
  }

  case AC::REPEAT_ONE: {
    this->repeat->setPixmap(ImageUtils::pixmap(QString(":/svg/repeat_all.svg"), QSize(17, 17), 1.0, Qt::white));
    this->repeat->setPixmap(ImageUtils::pixmap(QString(":/svg/repeat_all.svg"), QSize(17, 17), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

    this->repeatMode = AC::REPEAT_ALL;
    break;
  }

  case AC::REPEAT_ALL: {
    this->repeat->setPixmap(ImageUtils::pixmap(QString(":/svg/repeat.svg"), QSize(17, 17), 1.0, Qt::gray));
    this->repeat->setPixmap(ImageUtils::pixmap(QString(":/svg/repeat.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);

    this->repeatMode = AC::REPEAT_NONE;
    break;
  }

  default: {
    break;
  }
  }

  emit this->repeatClicked(this->repeatMode);
}

void AudioControls::onVolumeClicked()
{
  switch (this->volumeMode)
  {
  case AC::VOLUME_MUTED: {
    this->volume->setPixmap(ImageUtils::pixmap(QString(":/svg/volume.svg"), QSize(17, 17), 1.0, Qt::white));
    this->volume->setPixmap(ImageUtils::pixmap(QString(":/svg/volume.svg"), QSize(17, 17), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

    this->volumeMode = AC::VOLUME_NOT_MUTED;
    break;
  }

  case AC::VOLUME_NOT_MUTED: {
    this->volume->setPixmap(ImageUtils::pixmap(QString(":/svg/volume_muted.svg"), QSize(17, 17), 1.0, Qt::gray));
    this->volume->setPixmap(ImageUtils::pixmap(QString(":/svg/volume_muted.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);

    this->volumeMode = AC::VOLUME_MUTED;
    break;
  }

  default: {
    break;
  }
  }

  emit this->volumeClicked(this->volumeMode);
}

void AudioControls::onVolumeSliderMoved(int position)
{
  emit this->volumeSliderMoved(position);
}
