#include "util.h"

Util::Util()
{

}

QString Util::formatTime(qint64 timeInMillis)
{
    int totalSeconds = timeInMillis / 1000;
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    return QString("%1:%2")
            .arg(minutes, 2, 10, QChar('0'))
            .arg(seconds, 2, 10, QChar('0'));
}
