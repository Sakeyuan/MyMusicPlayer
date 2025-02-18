#include "logger.h"

Logger::Logger(QObject* parent) : QObject(parent) {}

Logger &Logger::instance()
{
    static Logger instance;
    return instance;
}

void Logger::init(const QString &logFilePath)
{
    try{
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(logFilePath.toStdString(),1024 * 1024 * 5, 3);
        auto error_file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("error_log.txt",1024 * 1024 * 5, 3);

        auto error_logger = std::make_shared<spdlog::logger>("ErrorLogger",spdlog::sinks_init_list{error_file_sink});
        auto logger = std::make_shared<spdlog::logger>("MyMusicPlayer",spdlog::sinks_init_list{console_sink,file_sink});

        spdlog::register_logger(logger);
        spdlog::register_logger(error_logger);

        spdlog::set_default_logger(logger);
        spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [%^%l%$] [%P] [Thread %t] [%F:%# %!] %v");
    }catch(const spdlog::spdlog_ex& ex){
        qDebug() << "日志初始化失败" << ex.what();
    }
}
