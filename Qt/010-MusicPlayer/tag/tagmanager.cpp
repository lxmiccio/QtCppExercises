#include "tagmanager.h"

#include <taglib/fileref.h>
#include <taglib/tag.h>

#include "tagutils.h"

QVariant TagManager::readTags(const QFileInfo &fileInfo)
{
  TagLib::FileRef fileRef(TagUtils::QStringToBuffer(fileInfo.canonicalFilePath()));

  if(fileRef.isNull() || !fileRef.tag()) {
    return QVariantMap();
  }

  QVariantMap tags;

  if(fileRef.audioProperties()) {
    tags["bitrate"] = fileRef.audioProperties()->bitrate();
    tags["duration"] = fileRef.audioProperties()->length();
  }

  tags["artist"] = TagUtils::StringToQString(fileRef.tag()->artist());
  tags["album"] = TagUtils::StringToQString(fileRef.tag()->album());
  tags["title"] = TagUtils::StringToQString(fileRef.tag()->title());
  tags["track"] = (quint8) fileRef.tag()->track();
  tags["year"] = fileRef.tag()->year();

  tags["mimetype"] = TagUtils::extensionToMimetype(fileInfo.suffix());

  tags["size"] = (quint64) fileInfo.size();
  tags["url"] = QString("file://%1").arg(fileInfo.canonicalFilePath());

  return tags;
}
