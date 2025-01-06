#pragma once

#include <string>
#include <fstream>
#include <mutex>

/*
 * 4种日志级别
 */
enum class LogLevel {
    DEBUG = 0,
    INFO,
    WARN,
    ERROR
};

class Logger {
public:

    static void init(const std::string &filename, LogLevel level, bool consoleOutput);

    static void setLevel(LogLevel level);
    static LogLevel getLevel();

    static void debug(const std::string &msg);
    static void info(const std::string &msg);
    static void warn(const std::string &msg);
    static void error(const std::string &msg);

private:

    static std::ofstream logFile_;
    static LogLevel logLevel_;
    static bool console_;
    static std::mutex logMutex_;
    static void writeLog(LogLevel lv, const std::string &msg);

    Logger() = delete;
    ~Logger() = delete;
};

LogLevel parseLogLevel(const std::string &str);