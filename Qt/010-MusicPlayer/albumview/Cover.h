#ifndef COVER_H
#define COVER_H

#include "QVBoxLayout"

#include "Album.h"
#include "ClickableLabel.h"
#include "ElidedLabel.h"

class Cover : public QWidget
{
  Q_OBJECT

  public:
    Cover(Album* album, QWidget* parent = 0);
    ~Cover();

    Album* album() const;

    static const quint16 COVER_HEIGHT = 215;
    static const quint16 COVER_WIDTH = 175;

    static const quint16 IMAGE_HEIGHT = 175;
    static const quint16 IMAGE_WIDTH = 175;

  private slots:
    void onClicked();

  signals:
    void clicked(const Album& album);

  private:
    Album* m_album;

    QVBoxLayout* m_layout;
    ClickableLabel* m_cover;
    ElidedLabel* m_albumTitle;
    ElidedLabel* m_artistName;
};

#endif // COVER_H
