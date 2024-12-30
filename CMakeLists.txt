cmake_minimum_required(VERSION 3.10)
project(MiniProHTTP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_subdirectory(src)      # 在src/CMakeLists.txt里再写更具体的构建
add_subdirectory(tests)    # 在tests/CMakeLists.txt里写测试的构建
enable_testing()
