#ifndef COVER_H
#define COVER_H

#include <QVBoxLayout>
#include <QObject>
#include <QWidget>
#include <QImage>

#include "elidedlabel.h"
#include "imagebutton.h"

#include "../engine/album.h"

class Cover : public QWidget
{
  Q_OBJECT

public:
  Cover(const Album* album, QWidget* parent = 0);

  const Album* getAlbum() {
    return this->album;
  }

private:
  const Album* album;

  ImageButton* cover;
  ElidedLabel* lblAlbum;
  ElidedLabel* lblArtist;
};

#endif // COVER_H
