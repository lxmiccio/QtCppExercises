#include "TagUtils.h"

#include <QMap>
#include <taglib/fileref.h>
#include <taglib/tag.h>

QVariant TagUtils::readTags(const QFileInfo &fileInfo)
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

char* TagUtils::QStringToBuffer(const QString& string)
{
  return string.toUtf8().data();
}

QString TagUtils::StringToQString(const TagLib::String& string)
{
  return QString(string.toCString(true));
}

QString TagUtils::extensionToMimetype(const QString& extension)
{
  static QMap<QString, QString> extToMime;

  if(extToMime.isEmpty()) {
    extToMime.insert("aac",  "audio/mp4");
    extToMime.insert("aif",  "audio/aiff");
    extToMime.insert("aiff", "audio/aiff");
    extToMime.insert("flac", "audio/flac");
    extToMime.insert("m4a",  "audio/mp4");
    extToMime.insert("mp3",  "audio/mpeg");
    extToMime.insert("mp4",  "audio/mp4");
    extToMime.insert("mpc",  "audio/x-musepack");
    extToMime.insert("oga",  "application/ogg");

#if defined(TAGLIB_MAJOR_VERSION) && defined(TAGLIB_MINOR_VERSION)
#if TAGLIB_MAJOR_VERSION >= 1 && TAGLIB_MINOR_VERSION >= 9
    extToMime.insert( "opus",  "application/opus" );
#endif
#endif

    extToMime.insert("ogg",  "application/ogg");
    extToMime.insert("opus",  "application/opus");
    extToMime.insert("wma",  "audio/x-ms-wma");
    extToMime.insert("wv",   "audio/x-wavpack");
  }

  return extToMime.value(extension.toLower(), "unknown");
}
