#include <gtest/gtest.h>
#include "../src/logger/Logger.h"
#include "../src/config/Config.h"

TEST(LoggerTest, BasicLog) {
    Logger::init("test.log", LogLevel::DEBUG, true);
    Logger::info("This is an info log.");
    Logger::debug("This debug might not show if level is WARN.");
    Logger::warn("Warning log. Should appear if level >= WARN.");
    Logger::error("Error log. Always shown if level >= ERROR.");
}

TEST(LoggerTest, ConfigLog) {
    auto cfg = Config::load("config.json");
    LogLevel level = parseLogLevel(cfg.getLogLevel());
    Logger::init("app.log", level, cfg.getConsoleOutput());
    Logger::info("This is an info log.");
    Logger::debug("This debug might not show if level is WARN.");
    Logger::warn("Warning log. Should appear if level >= WARN.");
    Logger::error("Error log. Always shown if level >= ERROR.");
}