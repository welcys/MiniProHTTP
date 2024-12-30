#include <gtest/gtest.h>
#include <atomic>
#include <chrono>
#include <thread>
#include "../src/threadpool/threadpool.h"  // 根据你的实际路径来

TEST(ThreadPoolTest, BasicTaskExecution) {
    // 建立一个包含4个工作线程的线程池
    ThreadPool pool(4);

    // 用原子变量记录任务执行次数
    std::atomic<int> counter{0};
    int numTasks = 10;

    // 提交10个任务
    for (int i = 0; i < numTasks; i++) {
        pool.enqueue([&counter]() {
            // 模拟一些耗时操作
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            ++counter;
        });
    }

    // 等待一定时间让任务完成（简单粗暴的做法）
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // 断言：counter 应该等于 numTasks
    EXPECT_EQ(counter.load(), numTasks);
}

TEST(ThreadPoolTest, StopEarly) {
    // 测试立即析构时，是否能优雅退出
    {
        ThreadPool pool(2);
        for(int i = 0; i < 5; i++){
            pool.enqueue([]{  
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                // 这里不做计数，只是测试是否崩溃
            });
        }
    } // pool析构，测试是否死锁或崩溃
    SUCCEED() << "ThreadPool destructed without crash.";
}

// Google Test 主函数，可以统一管理测试
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}