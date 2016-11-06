#ifndef TAGMANAGER_H
#define TAGMANAGER_H

#include <QFileInfo>
#include <QDateTime>
#include <QVariant>

#include <taglib/fileref.h>
#include <taglib/tag.h>

#include "utils.h"

class TagManager
{
public:
  static QVariant readTags(const QFileInfo& fileInfo);
};

#endif // TAGMANAGER_H
