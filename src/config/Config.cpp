#include "Config.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <stdexcept>  // 若想抛异常

using json = nlohmann::json;

Config Config::load(const std::string &filename) {
    Config cfg;  // 默认构造

    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Cannot open config file: " << filename << std::endl;
        // 可以抛异常，或只是让 cfg 保持默认值
        return cfg;
    }

    try {
        json j;
        inFile >> j;

        // 1. 端口
        if (j.contains("port") && j["port"].is_number()) {
            cfg.port_ = j["port"].get<int>();
        } else {
            // 若要严格，可抛异常或者写警告
            std::cerr << "[WARN] 'port' not found or not a number, using default "
                      << cfg.port_ << std::endl;
        }

        // 2. 线程池大小
        if (j.contains("threadPoolSize") && j["threadPoolSize"].is_number()) {
            cfg.threadPoolSize_ = j["threadPoolSize"].get<int>();
        } else {
            std::cerr << "[WARN] 'threadPoolSize' missing, default= "
                      << cfg.threadPoolSize_ << std::endl;
        }

        // 3. 日志级别 (string)
        if (j.contains("logLevel") && j["logLevel"].is_string()) {
            cfg.logLevel_ = j["logLevel"].get<std::string>();
        }

        // 4. docRoot
        if (j.contains("docRoot") && j["docRoot"].is_string()) {
            cfg.docRoot_ = j["docRoot"].get<std::string>();
        }

        // 5. consoleOutput (bool)，可选新字段
        if (j.contains("consoleOutput") && j["consoleOutput"].is_boolean()) {
            cfg.consoleOutput_ = j["consoleOutput"].get<bool>();
        } else {
            std::cerr << "[WARN] 'consoleOutput' missing, default= "
                      << cfg.consoleOutput_ << std::endl;
        }

    } catch (std::exception &e) {
        std::cerr << "[ERROR] JSON parse error: " << e.what() << std::endl;
        // 保持默认值
    }

    return cfg;
}