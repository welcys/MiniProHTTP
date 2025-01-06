include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.tar.gz
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# ---- test_threadpool ----
add_executable(test_threadpool test_threadpool.cpp)
target_link_libraries(test_threadpool
    PRIVATE
    gtest gtest_main pthread
    minipro_lib                # <-- 直接链接已有的库
)
target_include_directories(test_threadpool PRIVATE
    ${CMAKE_SOURCE_DIR}/src    # 如果头文件在 src 下
)
add_test(NAME test_threadpool COMMAND test_threadpool)

# ---- test_log ----
add_executable(test_log test_log.cpp)
target_link_libraries(test_log
    PRIVATE
    gtest gtest_main pthread
    minipro_lib                # <-- 同理
)
target_include_directories(test_log PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)
add_test(NAME test_log COMMAND test_log)