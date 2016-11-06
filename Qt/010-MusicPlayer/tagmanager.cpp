#include "tagmanager.h"

QVariant TagManager::readTags(const QFileInfo &fileInfo)
{
  TagLib::FileRef fileRef(fileInfo.canonicalFilePath().toUtf8().data());

  if(fileRef.isNull() || !fileRef.tag()) {
    return QVariantMap();
  }

  QVariantMap tags;

  if(fileRef.audioProperties()) {
    tags["bitrate"] = fileRef.audioProperties()->bitrate();
    tags["duration"] = fileRef.audioProperties()->length();
  }

  tags["artist"] = QString(fileRef.tag()->artist().toCString(true));
  tags["album"] = QString(fileRef.tag()->album().toCString(true));
  tags["title"] = QString(fileRef.tag()->title().toCString(true));
  tags["track"] = (quint8) fileRef.tag()->track();
  tags["year"] = fileRef.tag()->year();

  tags["mimetype"] = Utils::Utils::extensionToMimetype(fileInfo.suffix());

  tags["size"] = (quint64) fileInfo.size();
  tags["url"] = QString("file://%1").arg(fileInfo.canonicalFilePath());

  return tags;
}
