#pragma once

#include <string>

class Config {
public:
    static bool loadFromFile(const std::string &filePath);

    static int getPort();
    static int getThreadPoolSize();
    static std::string getLogLevel();
    static std::string getDocRoot();

private:
    // [Pitfall] 全局静态 => 只能有一套配置
    static int port_;
    static int threadPoolSize_;
    static std::string logLevel_;
    static std::string docRoot_;
};
