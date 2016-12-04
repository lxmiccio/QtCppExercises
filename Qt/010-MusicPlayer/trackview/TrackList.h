#ifndef TRACKTABLEVIEW_H
#define TRACKTABLEVIEW_H

#include <QTableView>

#include "SeekSlider.h"

class TrackList : public QTableView
{
    Q_OBJECT

    public:
        explicit TrackList(QWidget* parent = 0);

        static const quint8 TRACK = 0;
        static const quint8 TITLE = 1;
        static const quint8 ALBUM = 2;
        static const quint8 ARTIST = 3;
        static const quint8 DURATION = 4;

        static const quint8 TRACK_WIDTH = 100;
        static constexpr double TITLE_WIDTH_PERCENTAGE = 0.4;
        static constexpr double ALBUM_WIDTH_PERCENTAGE = 0.4;
        static constexpr double ARTIST_WIDTH_PERCENTAGE = 0.2;
        static const quint8 DURATION_WIDTH = 100;

        static const quint8 LEFT_MARGIN = 38;
        static const quint8 MARGIN = 10;
        static const quint8 RIGHT_MARGIN = 38;
        static const quint8 RIGHT_MARGIN_SCROLLBAR = RIGHT_MARGIN + SeekSlider::WIDTH * 2;

    protected:
        virtual void resizeEvent(QResizeEvent* event);
};

#endif // TRACKTABLEVIEW_H
