#include "Config.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

// [Pitfall] 静态变量 => 全局只有一份
int Config::port_ = 8080;
int Config::threadPoolSize_ = 4;
std::string Config::logLevel_ = "INFO";
std::string Config::docRoot_ = "./www";

bool Config::loadFromFile(const std::string &filePath) {
    std::ifstream ifs(filePath);
    if(!ifs.is_open()) {
        std::cerr << "[Pitfall] Config: cannot open " << filePath << std::endl;
        return false;
    }
    try {
        nlohmann::json j;
        ifs >> j;
        // [Pitfall] 没做严格类型检查, key错写也不会报错
        if(j.contains("port")) {
            port_ = j["port"].get<int>(); // [Pitfall] 如果是字符串，会抛异常
        }
        if(j.contains("threadPoolSize")) {
            threadPoolSize_ = j["threadPoolSize"].get<int>();
        }
        if(j.contains("logLevel")) {
            logLevel_ = j["logLevel"].get<std::string>(); 
        }
        if(j.contains("docRoot")) {
            docRoot_ = j["docRoot"].get<std::string>();
        }
        return true;
    } catch(std::exception &e) {
        std::cerr << "[Pitfall] Config parse error: " << e.what() << std::endl;
        return false;
    }
}

int Config::getPort() {
    return port_;
}
int Config::getThreadPoolSize() {
    return threadPoolSize_;
}
std::string Config::getLogLevel() {
    return logLevel_;
}
std::string Config::getDocRoot() {
    return docRoot_;
}
