#ifndef AUTHOR_H
#define AUTHOR_H

#pragma once

#include <QList>
#include <QString>

#include "track.fwd.h"
#include "author.fwd.h"

class Author
{
private:
    QString name;
    QList<Track*> tracks;

public:
    Author();
    Author(QString name);
    Author(QString name, QList<Track*> tracks);

    void setName(QString name);
    QString getName();

    QList<Track*> getTracks();

    bool isExistingTrack(Track* track);
};

QDataStream& operator<<(QDataStream& out, Author& author);
QDataStream& operator>>(QDataStream& in, Author& author);

#endif // AUTHOR_H
