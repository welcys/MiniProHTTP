#include "config/Config.h"
#include "logger/Logger.h"

int main() {
    auto cfg = Config::load("config.json");

    // 将 string => LogLevel
    LogLevel level = parseLogLevel(cfg.getLogLevel());

    // 初始化日志: filename固定写 "app.log" 或也从配置文件读 (你可以自己加 config 字段 "logFile" )
    Logger::init("app.log", level, cfg.getConsoleOutput());

    Logger::info("This is an info log.");
    Logger::debug("This debug might not show if level is WARN.");
    Logger::warn("Warning log. Should appear if level >= WARN.");
    Logger::error("Error log. Always shown if level >= ERROR.");

    return 0;
}