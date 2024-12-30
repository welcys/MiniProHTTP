# tests/CMakeLists.txt

# 由于我们需要用到外部的 Google Test，这里采用 FetchContent 的方式拉取 gtest 源码并自动编译安装
include(FetchContent)

# 声明我们要拉取哪个版本的 gtest；URL 可以改成你喜欢的版本
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.tar.gz
)

# 使 gtest 可用
FetchContent_MakeAvailable(googletest)

# 启用测试功能
enable_testing()

# 建立一个可执行程序用于跑测试，比如 test_threadpool
add_executable(test_threadpool
    test_threadpool.cpp
    ../src/threadpool/threadpool.cpp
)

# 链接 Google Test 库
target_link_libraries(test_threadpool
    PRIVATE
    gtest gtest_main pthread
)

# 如果你的 ThreadPool 头文件在 src/threadpool/ 里，且你需要访问它
# 可以指定头文件目录。例如：
target_include_directories(test_threadpool PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    # 或者 ${CMAKE_SOURCE_DIR}/src/threadpool
)

# 告诉 CTest 这是一个可运行测试
add_test(NAME test_threadpool COMMAND test_threadpool)
