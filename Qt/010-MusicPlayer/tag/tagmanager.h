#ifndef TAGMANAGER_H
#define TAGMANAGER_H

#include <QFileInfo>
#include <QVariant>

class TagManager
{
  public:
    static QVariant readTags(const QFileInfo& fileInfo);
};

#endif // TAGMANAGER_H
