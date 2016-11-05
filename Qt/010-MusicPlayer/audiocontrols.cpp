#include "audiocontrols.h"

#include <QFontDatabase>
#include "imageloader.h"

AC::AudioControls::AudioControls(QWidget* parent) : BackgroundWidget(parent)
{
  QImage i("images/tovelo.jpg");
  this->setBackground(QPixmap::fromImage(ImageLoader::blur(i, i.rect(), 30, false, true)));

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

  this->fastBackward = new GuiUtils::ImageButton();
  this->fastBackward->setPixmap(ImageLoader::pixmap(QString("images/fast_backward.svg"), QSize(17, 17), 1.0, Qt::gray));
  this->fastBackward->setPixmap(ImageLoader::pixmap(QString("images/fast_backward.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);
  QObject::connect(this->fastBackward, SIGNAL(clicked()), this, SLOT(onFastBackwardClicked()));

  this->lowerSpacer2 = new QSpacerItem(16, 8, QSizePolicy::Fixed);

  this->backward = new GuiUtils::ImageButton();
  this->backward->setPixmap(ImageLoader::pixmap(QString("images/backward.svg"), QSize(17, 17), 1.0, Qt::gray));
  this->backward->setPixmap(ImageLoader::pixmap(QString("images/backward.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);
  QObject::connect(this->backward, SIGNAL(clicked()), this, SLOT(onBackwardClicked()));

  this->lowerSpacer3 = new QSpacerItem(16, 8, QSizePolicy::Fixed);

  this->play = new GuiUtils::ImageButton();
  this->play->setPixmap(ImageLoader::pixmap(QString("images/play.svg"), QSize(17, 17), 1.0, Qt::gray));
  this->play->setPixmap(ImageLoader::pixmap(QString("images/play.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);
  QObject::connect(this->play, SIGNAL(clicked()), this, SLOT(onPlayClicked()));

  this->pause = new GuiUtils::ImageButton();
  this->pause->setPixmap(ImageLoader::pixmap(QString("images/pause.svg"), QSize(17, 17), 1.0, Qt::gray));
  this->pause->setPixmap(ImageLoader::pixmap(QString("images/pause.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);
  this->pause->hide();
  QObject::connect(this->pause, SIGNAL(clicked()), this, SLOT(onPauseClicked()));

  this->lowerSpacer4 = new QSpacerItem(16, 8, QSizePolicy::Fixed);

  this->forward = new GuiUtils::ImageButton();
  this->forward->setPixmap(ImageLoader::pixmap(QString("images/forward.svg"), QSize(17, 17), 1.0, Qt::gray));
  this->forward->setPixmap(ImageLoader::pixmap(QString("images/forward.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);
  QObject::connect(this->forward, SIGNAL(clicked()), this, SLOT(onForwardClicked()));

  this->lowerSpacer5 = new QSpacerItem(16, 8, QSizePolicy::Fixed);

  this->fastForward = new GuiUtils::ImageButton();
  this->fastForward->setPixmap(ImageLoader::pixmap(QString("images/fast_forward.svg"), QSize(17, 17), 1.0, Qt::gray));
  this->fastForward->setPixmap(ImageLoader::pixmap(QString("images/fast_forward.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);
  QObject::connect(this->fastForward, SIGNAL(clicked()), this, SLOT(onFastForwardClicked()));

  this->lowerSpacer6 = new QSpacerItem(120, 8, QSizePolicy::Fixed);

  font.setBold(true);
  font.setPointSize(10);

  this->eslapsedTime = new QLabel("00:00");
  this->eslapsedTime->setFont(font);
  this->eslapsedTime->setStyleSheet(QString("color: white; margin-top: -2px;"));

  this->lowerSpacer7 = new QSpacerItem(6, 8, QSizePolicy::Fixed);

  this->musicSlider = new GuiUtils::SeekSlider(Qt::Horizontal);
  this->musicSlider->setFixedHeight(6);
  this->musicSlider->setMinimumWidth(256);

  this->musicSlider->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
  QObject::connect(this->musicSlider, SIGNAL(sliderMoved(int)), this, SLOT(onMusicSliderMoved(int)));

  this->lowerSpacer8 = new QSpacerItem(6, 8, QSizePolicy::Fixed);

  this->remainingTime = new QLabel("00:00");
  this->remainingTime->setFont(font);
  this->remainingTime->setStyleSheet(QString("color: white; margin-top: -2px;"));

  this->lowerSpacer9 = new QSpacerItem(36, 8, QSizePolicy::Fixed);

  this->shuffle = new GuiUtils::ImageButton();
  this->shuffle->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  this->shuffle->setPixmap(ImageLoader::pixmap(QString("images/shuffle.svg"), QSize(17, 17), 1.0, Qt::gray));
  this->shuffle->setPixmap(ImageLoader::pixmap(QString("images/shuffle.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);
  QObject::connect(this->shuffle, SIGNAL(clicked()), this, SLOT(onShuffleClicked()));

  this->lowerSpacer10 = new QSpacerItem(36, 8, QSizePolicy::Fixed);

  this->repeat = new GuiUtils::ImageButton();
  this->repeat->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  this->repeat->setPixmap(ImageLoader::pixmap(QString("images/repeat.svg"), QSize(17, 17), 1.0, Qt::gray));
  this->repeat->setPixmap(ImageLoader::pixmap(QString("images/repeat.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);
  QObject::connect(this->repeat, SIGNAL(clicked()), this, SLOT(onRepeatClicked()));

  this->lowerSpacer11 = new QSpacerItem(36, 8, QSizePolicy::Fixed);

  this->volume = new GuiUtils::ImageButton();
  this->volume->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  this->volume->setPixmap(ImageLoader::pixmap(QString("images/volume.svg"), QSize(17, 17), 1.0, Qt::white));
  this->volume->setPixmap(ImageLoader::pixmap(QString("images/volume.svg"), QSize(17, 17), 1.0, Qt::gray), QIcon::Off, QIcon::Active);
  QObject::connect(this->volume, SIGNAL(clicked()), this, SLOT(onVolumeClicked()));

  this->volumeSlider = new GuiUtils::SeekSlider(Qt::Horizontal);
  this->volumeSlider->setFixedHeight(6);
  this->volumeSlider->setMinimumWidth(120);
  this->volumeSlider->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  QObject::connect(this->volumeSlider, SIGNAL(sliderMoved(int)), this, SLOT(onVolumeSliderMoved(int)));

  this->lowerSpacer12 = new QSpacerItem(24, 8, QSizePolicy::Fixed);

  this->lowerHorizontalLayout = new QHBoxLayout();
  this->lowerHorizontalLayout->addItem(this->lowerSpacer1);
  this->lowerHorizontalLayout->addWidget(this->fastBackward);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer2);
  this->lowerHorizontalLayout->addWidget(this->backward);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer3);
  this->lowerHorizontalLayout->addWidget(this->play);
  this->lowerHorizontalLayout->addWidget(this->pause);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer4);
  this->lowerHorizontalLayout->addWidget(this->forward);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer5);
  this->lowerHorizontalLayout->addWidget(this->fastForward);
  this->lowerHorizontalLayout->addItem(this->lowerSpacer6);
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

void AC::AudioControls::showPlay(bool show)
{
  show ? this->play->show() : this->play->hide();
}

void AC::AudioControls::showPause(bool show)
{
  show ? this->pause->show() : this->pause->hide();
}

void AC::AudioControls::onCurrentMediaChanged(Track& track)
{
  this->artist->setText(track.getArtist());
  this->track->setText(track.getTitle());
}

void AC::AudioControls::onPositionChanged(qint64 position, qint64 duration)
{
  if(duration != 0) {
    this->musicSlider->setValue((this->musicSlider->maximum() - this->musicSlider->minimum()) * position / duration);
  }
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
  emit this->musicSliderMoved(position, this->musicSlider->minimum(), this->musicSlider->maximum());
}

void AC::AudioControls::onShuffleClicked()
{
  switch (this->shuffleMode)
  {
  case AC::SHUFFLE_OFF: {
    this->shuffle->setPixmap(ImageLoader::pixmap(QString("images/shuffle.svg"), QSize(17, 17), 1.0, Qt::white));
    this->shuffle->setPixmap(ImageLoader::pixmap(QString("images/shuffle.svg"), QSize(17, 17), 0.5, Qt::gray), QIcon::Off, QIcon::Active);

    this->shuffleMode = AC::SHUFFLE_ON;
    break;
  }

  case AC::SHUFFLE_ON: {
    this->shuffle->setPixmap(ImageLoader::pixmap(QString("images/shuffle.svg"), QSize(17, 17), 1.0, Qt::gray));
    this->shuffle->setPixmap(ImageLoader::pixmap(QString("images/shuffle.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);

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
    this->repeat->setPixmap(ImageLoader::pixmap(QString("images/repeat_one.svg"), QSize(17, 17), 1.0, Qt::white));
    this->repeat->setPixmap(ImageLoader::pixmap(QString("images/repeat_one.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);

    this->repeatMode = AC::REPEAT_ONE;
    break;
  }

  case AC::REPEAT_ONE: {
    this->repeat->setPixmap(ImageLoader::pixmap(QString("images/repeat_all.svg"), QSize(17, 17), 1.0, Qt::white));
    this->repeat->setPixmap(ImageLoader::pixmap(QString("images/repeat_all.svg"), QSize(17, 17), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

    this->repeatMode = AC::REPEAT_ALL;
    break;
  }

  case AC::REPEAT_ALL: {
    this->repeat->setPixmap(ImageLoader::pixmap(QString("images/repeat.svg"), QSize(17, 17), 1.0, Qt::gray));
    this->repeat->setPixmap(ImageLoader::pixmap(QString("images/repeat.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);

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
    this->volume->setPixmap(ImageLoader::pixmap(QString("images/volume.svg"), QSize(17, 17), 1.0, Qt::white));
    this->volume->setPixmap(ImageLoader::pixmap(QString("images/volume.svg"), QSize(17, 17), 1.0, Qt::gray), QIcon::Off, QIcon::Active);

    this->volumeMode = AC::VOLUME_NOT_MUTED;
    break;
  }

  case AC::VOLUME_NOT_MUTED: {
    this->volume->setPixmap(ImageLoader::pixmap(QString("images/volume_muted.svg"), QSize(17, 17), 1.0, Qt::gray));
    this->volume->setPixmap(ImageLoader::pixmap(QString("images/volume_muted.svg"), QSize(17, 17), 1.0, Qt::white), QIcon::Off, QIcon::Active);

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
