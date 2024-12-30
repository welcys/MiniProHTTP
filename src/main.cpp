#include <iostream>
#include "logger/Logger.h"
#include "config/Config.h"

int main() {
    // 假设 config.json 在同级目录
    Config::loadFromFile("config.json"); // 读取port、threadPoolSize、logLevel、docRoot
    
    // 根据配置里的 logLevel 初始化日志
    std::string levelStr = Config::getLogLevel(); // e.g. "DEBUG"
    LogLevel logLv = LogLevel::INFO;
    if(levelStr == "DEBUG") logLv = LogLevel::DEBUG;
    else if(levelStr == "WARN") logLv = LogLevel::WARN;
    else if(levelStr == "ERROR") logLv = LogLevel::ERROR;

    Logger::init("server.log", logLv, true);

    Logger::info("Server is starting...");
    Logger::info("Port = " + std::to_string(Config::getPort()));
    Logger::info("ThreadPool Size = " + std::to_string(Config::getThreadPoolSize()));
    Logger::info("DocRoot = " + Config::getDocRoot());

    Logger::debug("This is a debug message");
    Logger::warn("This is a warning message");
    Logger::error("This is an error message");

    // Day 1 的线程池你可以在这边也测试一下
    // ...
    
    return 0;
}
