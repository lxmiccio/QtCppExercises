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
};

#endif // AUDIOCONTROLS_H
