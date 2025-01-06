#pragma once

#include <string>

class Config {
public:
    // 构造函数
    Config() = default;

    // 静态方法：从文件加载配置并生成一个 Config 对象
    static Config load(const std::string &filename);

    // 访问方法
    int getPort() const { return port_; }
    int getThreadPoolSize() const { return threadPoolSize_; }
    std::string getLogLevel() const { return logLevel_; }
    std::string getDocRoot() const { return docRoot_; }
    bool getConsoleOutput() const { return consoleOutput_; }
private:
    int port_ = 8080;
    int threadPoolSize_ = 4;
    std::string logLevel_ = "INFO";
    std::string docRoot_ = "./www";
    bool consoleOutput_ = true;
};