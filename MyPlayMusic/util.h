#ifndef UTIL_H
#define UTIL_H

#include <QString>

class Util
{
public:
    Util();
    static QString formatTime(qint64 timeInMillis);
};

#endif // UTIL_H
