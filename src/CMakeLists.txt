# src/CMakeLists.txt (或顶层)
include(FetchContent)

FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG        v3.11.2
)
FetchContent_MakeAvailable(json)

add_library(minipro_lib
    threadpool/threadpool.cpp
    logger/Logger.cpp
    config/Config.cpp
)
# 让 minipro_lib 使用 nlohmann_json
target_link_libraries(minipro_lib PRIVATE nlohmann_json)

add_executable(MiniProHTTP main.cpp)
# 现在只需要链接 minipro_lib 即可
target_link_libraries(MiniProHTTP PRIVATE minipro_lib)
