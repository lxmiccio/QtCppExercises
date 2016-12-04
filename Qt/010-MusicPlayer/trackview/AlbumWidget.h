#ifndef ALBUMWIDGET_H
#define ALBUMWIDGET_H

#include <QLabel>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QWidget>

#include "Album.h"

class AlbumWidget : public QWidget
{
public:
    explicit AlbumWidget(QWidget* parent = 0);
    ~AlbumWidget();

    void setAlbum(const Album* album);

    static const quint16 WIDGET_HEIGHT = 275;
    static const quint16 WIDGET_WIDTH = 200;

    static const quint16 IMAGE_HEIGHT = 200;
    static const quint16 IMAGE_WIDTH = 200;

private:
    const Album* c_album;

    QLabel* m_cover;
    QSpacerItem* m_spacer1;
    QLabel* m_albumTitle;
    QSpacerItem* m_spacer2;
    QLabel* m_artistName;
    QSpacerItem* m_spacer3;
    QVBoxLayout* m_layout;
};

#endif // ALBUMWIDGET_H
