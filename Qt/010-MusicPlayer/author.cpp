#include "author.h"

Author::Author()
{
    this->tracks = QList<Track*>();
}

Author::Author(QString name)
{
    this->name = name;
    this->tracks = QList<Track*>();
}

Author::Author(QString name, QList<Track *> tracks)
{
    this->name = name;
    this->tracks = tracks;
}

void Author::setName(QString name)
{
    this->name = name;
}

QString Author::getName()
{
    return this->getName();
}

QList<Track*> Author::getTracks()
{
    return this->tracks;
}

bool Author::isExistingTrack(Track* track)
{
    return this->tracks.indexOf(track);
}

QDataStream& operator<<(QDataStream& out, Author& author)
{
    out << author.getName();
        // << author.getTracks();

    return out;
}

QDataStream& operator>>(QDataStream& in, Author& author)
{
    QString name;
    QList<Track*> tracks;

    in >> name;
         // >> tracks;

    author = Author(name, tracks);

    return in;
}
