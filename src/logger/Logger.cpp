#include "Logger.h"
#include <iostream>
#include <chrono>
#include <ctime>

std::ofstream Logger::logFile_;
LogLevel Logger::logLevel_ = LogLevel::DEBUG;
bool Logger::console_ = true;
std::mutex Logger::logMutex_;

static std::string getCurrentTimeString() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    char buf[32];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&t));
    return buf;
}

void Logger::init(const std::string &filename, LogLevel level, bool consoleOutput) {
    logFile_.open(filename, std::ios::app);
    if(!logFile_.is_open()) {
        std::cerr << " Logger failed to open file: " << filename << std::endl;
    }
    logLevel_ = level;
    console_ = consoleOutput;
}

void Logger::setLevel(LogLevel level) {
    std::lock_guard<std::mutex> lock(logMutex_);
    logLevel_ = level;
}

LogLevel Logger::getLevel() {
    std::lock_guard<std::mutex> lock(logMutex_);
    return logLevel_;
}

void Logger::writeLog(LogLevel lv, const std::string &msg) {

    std::lock_guard<std::mutex> lock(Logger::logMutex_);
    if(lv < Logger::logLevel_) {  //如果日志级别低于设置的级别，则不输出
        return;
    }

    // 构造日志行
    std::string levelStr;
    switch (lv) {
        case LogLevel::DEBUG: levelStr = "DEBUG"; break;
        case LogLevel::INFO:  levelStr = "INFO "; break;
        case LogLevel::WARN:  levelStr = "WARN "; break;
        case LogLevel::ERROR: levelStr = "ERROR"; break;
    }
    std::string logLine = "[" + getCurrentTimeString() + "][" + levelStr + "] " + msg + "\n";

    // 写文件
    if(Logger::logFile_.is_open()) {
        Logger::logFile_ << logLine;
        Logger::logFile_.flush(); 
    }

    // 同时输出到控制台
    if(Logger::console_) {
        if(lv == LogLevel::WARN || lv == LogLevel::ERROR) {
            std::cerr << logLine;
        } else {
            std::cout << logLine;
        }
    }
}

void Logger::debug(const std::string &msg) {
    writeLog(LogLevel::DEBUG, msg);
}
void Logger::info(const std::string &msg) {
    writeLog(LogLevel::INFO, msg);
}
void Logger::warn(const std::string &msg) {
    writeLog(LogLevel::WARN, msg);
}
void Logger::error(const std::string &msg) {
    writeLog(LogLevel::ERROR, msg);
}

LogLevel parseLogLevel(const std::string& levelStr) {
    if (levelStr == "DEBUG") return LogLevel::DEBUG;
    else if (levelStr == "INFO") return LogLevel::INFO;
    else if (levelStr == "WARN") return LogLevel::WARN;
    else if (levelStr == "ERROR") return LogLevel::ERROR;
    // 可以加一个默认
    return LogLevel::INFO;
}