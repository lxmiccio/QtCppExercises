#ifndef AUDIOCONTROLS_H
#define AUDIOCONTROLS_H

#include <QObject>
#include <QWidget>

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QLabel>
#include <QSlider>
#include <QSpacerItem>

#include "imagebutton.h"
#include "track.h"

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

  class AudioControls : public QWidget
  {
    Q_OBJECT

  public:
    explicit AudioControls(QWidget *parent = 0);

  protected:

  private:
    QVBoxLayout* verticalLayout;
    QHBoxLayout* upperHorizontalLayout;
    QSpacerItem* upperSpacer1;
    QLabel* artist;
    QLabel* dash;
    QLabel* track;
    QSpacerItem* upperSpacer2;
    QHBoxLayout* lowerHorizontalLayout;
    ImageButton* fastBackward;
    QSpacerItem* lowerSpacer1;
    ImageButton* backward;
    QSpacerItem* lowerSpacer2;
    ImageButton* play;
    ImageButton* pause;
    QSpacerItem* lowerSpacer3;
    ImageButton* forward;
    QSpacerItem* lowerSpacer4;
    ImageButton* fastForward;
    QSpacerItem* lowerSpacer5;
    QLabel* eslapsedTime;
    QSpacerItem* lowerSpacer6;
    QSlider* musicSlider;
    QSpacerItem* lowerSpacer7;
    QLabel* remainingTime;
    QSpacerItem* lowerSpacer8;
    ImageButton* shuffle;
    QSpacerItem* lowerSpacer9;
    ImageButton* repeat;
    QSpacerItem* lowerSpacer10;
    ImageButton* volume;
    QSlider* volumeSlider;

    RepeatMode_t repeatMode;
    ShuffleMode_t shuffleMode;
    VolumeMode_t volumeMode;

  public slots:
    void onMediaChanged(Track& track);

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
    void musicSliderMoved(int position);
    void shuffleClicked(AC::ShuffleMode_t shuffleMode);
    void repeatClicked(AC::RepeatMode_t repeatMode);
    void volumeClicked(AC::VolumeMode_t volumeMode);
    void volumeSliderMoved(int position);
  };

  #endif // AUDIOCONTROLS_H
}
