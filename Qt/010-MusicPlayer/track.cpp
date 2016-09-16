#include "track.h"

#include "author.h"

Track::Track()
{

}

Track::Track(QString title)
{
    this->title = title;
}

Track::Track(Author *author, QString title)
{
    this->author = author;
    this->title = title;
}

void Track::setAuthor(Author* author)
{
    this->author = author;
}

Author* Track::getAuthor()
{
    return this->author;
}

QString Track::getTitle()
{
    return this->title;
}

QDataStream& operator<<(QDataStream& out, Track& track)
{
    out // << track.getAuthor()
        << track.getTitle();

    return out;
}

QDataStream& operator>>(QDataStream& in, Track& track)
{
    Author author;
    QString title;

    in // >> author;
       >> title;

    track = Track(&author, title);

    return in;
}

