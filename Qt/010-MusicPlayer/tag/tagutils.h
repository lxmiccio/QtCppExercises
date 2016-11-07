#ifndef TAGUTILS_H
#define TAGUTILS_H

#include <QString>

#include "taglib/tag.h"

class TagUtils
{
  public:
    static char* QStringToBuffer(const QString& string);
    static QString StringToQString(const TagLib::String& string);

    static QString extensionToMimetype(const QString &extension);
};

#endif // TAGUTILS_H
