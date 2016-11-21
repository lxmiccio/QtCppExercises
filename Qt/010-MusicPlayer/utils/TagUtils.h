#ifndef TAGUTILS_H
#define TAGUTILS_H

#include <QString>
#include <QFileInfo>
#include <QVariant>

#include "taglib/tag.h"

class TagUtils
{
  public:
    static QVariant readTags(const QFileInfo& fileInfo);

    static char* QStringToBuffer(const QString& string);
    static QString StringToQString(const TagLib::String& string);

    static QString extensionToMimetype(const QString &extension);
};

#endif // TAGUTILS_H
