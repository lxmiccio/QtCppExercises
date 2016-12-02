#ifndef ALBUMWIDGET_H
#define ALBUMWIDGET_H

#include <QLabel>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QWidget>

#include "ElidedLabel.h"

#include "Album.h"

class AlbumWidget : public QWidget
{
public:
    explicit AlbumWidget(QWidget* parent = 0);
    ~AlbumWidget();

    void setAlbum(const Album* album);

private:
    const Album* c_album;

    QLabel* m_cover;
    QSpacerItem* m_spacer1;
    ElidedLabel* m_albumTitle;
    QSpacerItem* m_spacer2;
    ElidedLabel* m_artistName;
    QSpacerItem* m_spacer3;
    QVBoxLayout* m_layout;
};

#endif // ALBUMWIDGET_H
