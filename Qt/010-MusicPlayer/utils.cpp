#include "utils.h"

#include <QMap>

QString Utils::Utils::extensionToMimetype(const QString &extension)
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
