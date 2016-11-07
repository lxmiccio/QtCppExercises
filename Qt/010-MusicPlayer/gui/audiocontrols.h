#ifndef AUDIOCONTROLS_H
#define AUDIOCONTROLS_H

#include <QHBoxLayout>
#include <QLabel>
#include <QObject>
#include <QSlider>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QWidget>

#include <QTimeLine>

#include "gui/backgroundwidget.h"
#include "gui/imagebutton.h"
#include "gui/seekslider.h"
#include "engine/track.h"

namespace AC
{
  typedef enum ShuffleMode
  {
    SHUFFLE_OFF = 0,
    SHUFFLE_ON
  }
  ShuffleMode_t;

  typedef enum RepeatMode
  {
    REPEAT_NONE = 0,
    REPEAT_ONE,
    REPEAT_ALL
  }
  RepeatMode_t;

  typedef enum VolumeMode
  {
    VOLUME_MUTED = 0,
    VOLUME_NOT_MUTED
  }
  VolumeMode_t;
}

class AudioControls : public BackgroundWidget
{
  Q_OBJECT

  public:
    explicit AudioControls(QWidget* parent = 0);

    void showPlay(bool show);
    void showPause(bool show);

  private:
    QVBoxLayout* verticalLayout;
    QHBoxLayout* upperHorizontalLayout;
    QSpacerItem* upperSpacer1;
    QLabel* artist;
    QLabel* dash;
    QLabel* track;
    QSpacerItem* upperSpacer2;
    QHBoxLayout* lowerHorizontalLayout;
    QSpacerItem* lowerSpacer1;
    ImageButton* fastBackward;
    QSpacerItem* lowerSpacer2;
    ImageButton* backward;
    QSpacerItem* lowerSpacer3;
    ImageButton* play;
    ImageButton* pause;
    QSpacerItem* lowerSpacer4;
    ImageButton* forward;
    QSpacerItem* lowerSpacer5;
    ImageButton* fastForward;
    QSpacerItem* lowerSpacer6;
    QLabel* eslapsedTime;
    QSpacerItem* lowerSpacer7;
    SeekSlider* musicSlider;
    QSpacerItem* lowerSpacer8;
    QLabel* remainingTime;
    QSpacerItem* lowerSpacer9;
    ImageButton* shuffle;
    QSpacerItem* lowerSpacer10;
    ImageButton* repeat;
    QSpacerItem* lowerSpacer11;
    ImageButton* volume;
    QSlider* volumeSlider;
    QSpacerItem* lowerSpacer12;

    AC::RepeatMode_t repeatMode;
    AC::ShuffleMode_t shuffleMode;
    AC::VolumeMode_t volumeMode;

  public slots:
    void onCurrentMediaChanged(Track& track);
    void onPositionChanged(qint64 position, qint64 duration);

  private slots:
    void onFastBackwardClicked();
    void onBackwardClicked();
    void onPlayClicked();
    void onPauseClicked();
    void onForwardClicked();
    void onFastForwardClicked();
    void onMusicSliderMoved(int position);
    void onShuffleClicked();
    void onRepeatClicked();
    void onVolumeClicked();
    void onVolumeSliderMoved(int position);

  signals:
    void fastBackwardClicked();
    void backwardClicked();
    void playClicked();
    void pauseClicked();
    void forwardClicked();
    void fastForwardClicked();
    void musicSliderMoved(int position, int minimum, int maximum);
    void shuffleClicked(AC::ShuffleMode_t shuffleMode);
    void repeatClicked(AC::RepeatMode_t repeatMode);
    void volumeClicked(AC::VolumeMode_t volumeMode);
    void volumeSliderMoved(int position);
};

#endif // AUDIOCONTROLS_H
