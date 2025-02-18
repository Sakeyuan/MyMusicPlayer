#ifndef LOGGER_H
#define LOGGER_H
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <QObject>
#include <QDebug>
#include "QLogFormatter.h"

class Logger : public QObject
{
    Q_OBJECT
public:
    static Logger& instance();

    void init(const QString& logFilePath = "log/app.log");

    template<typename... Args>
    void info(const QString& msg,Args&&...args){
        spdlog::get("MyMusicPlayer")->info(msg.toStdString(),std::forward<Args>(args)...);
    }

    template<typename... Args>
    void warn(const QString& msg,Args&&...args){
        spdlog::get("MyMusicPlayer")->warn(msg.toStdString(),std::forward<Args>(args)...);
    }

    template<typename... Args>
    void error(const QString& msg,Args&&...args){
        spdlog::get("MyMusicPlayer")->error(msg.toStdString(),std::forward<Args>(args)...);
    }

private:
    explicit Logger(QObject* parent = nullptr);
};

#endif // LOGGER_H
