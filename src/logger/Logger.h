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
    // [Pitfall] 全是静态方法 + 静态成员 => 只能有一份全局 Logger
    static void init(const std::string &filename, LogLevel level, bool consoleOutput);

    static void setLevel(LogLevel level);
    static LogLevel getLevel();

    static void debug(const std::string &msg);
    static void info(const std::string &msg);
    static void warn(const std::string &msg);
    static void error(const std::string &msg);

private:
    // [Pitfall] 全局静态，无法支持多通道日志
    static std::ofstream logFile_;
    static LogLevel logLevel_;
    static bool console_;
    static std::mutex logMutex_;

    static void writeLog(LogLevel lv, const std::string &msg);

    // [Pitfall] init也没有做多线程安全保证
    Logger() = delete;
    ~Logger() = delete;
};
