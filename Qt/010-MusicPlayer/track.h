#ifndef TRACK_H
#define TRACK_H

#pragma once

#include <QString>

#include "author.fwd.h"
#include "track.fwd.h"

class Track
{
private:
    Author* author;
    QString title;

public:
    Track();
    Track(QString title);
    Track(Author* author, QString title);

    void setAuthor(Author* author);
    Author* getAuthor();

    QString getTitle();
};

QDataStream& operator<<(QDataStream& out, Track& track);
QDataStream& operator>>(QDataStream& in, Track& track);

#endif // TRACK_H
