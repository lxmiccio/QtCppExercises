#ifndef UTILS_H
#define UTILS_H

#include <QString>

namespace Utils
{
  class Utils
  {
    public:
      static QString extensionToMimetype(const QString &extension);
  };
}

#endif // UTILS_H
