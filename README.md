MiniPro-HTTP (Day 1)

简介

这是一个使用 C++ 编写的轻量级服务器项目 MiniPro-HTTP。在 Day 1，我实现了一个可复用的线程池，并使用 Google Test (GTest) 对它进行单元测试。这是项目的第一步，为后续的网络编程、HTTP 处理等部分打下并发基础。

主要功能
	1.	线程池 (ThreadPool)
	•	封装 std::thread, std::mutex, std::condition_variable 实现多线程工作队列
	•	支持提交新任务 (enqueue)，由线程池自动调度执行
	•	在析构时优雅停止，等待所有工作线程退出
	2.	Google Test 测试 (GTest)
	•	我使用了 Google Test 对线程池功能做基础验证：
	•	提交多任务并检查任务执行次数
	•	测试线程池析构时能否稳定退出等

目录结构

当前（Day 1）主要的代码文件如下：

MiniPro-HTTP/
├── CMakeLists.txt         # 顶层CMake配置（简单编译、测试集成）
├── src/
│   ├── main.cpp           # 入口文件 (可先空着或做简单演示)
│   └── threadpool/
│       ├── threadpool.h   # 线程池类的声明
│       └── threadpool.cpp # 线程池类的实现
├── tests/
│   ├── CMakeLists.txt     # 测试的CMake配置
│   ├── test_threadpool.cpp # GTest测试线程池功能
└── ...

	后续随着项目发展，你会在 src/ 下新增更多模块（logger、config、network 等）。

如何编译 & 运行
	1.	获取源码 & 进入项目目录

git clone https://github.com/YourName/MiniProHTTP.git
cd MiniProHTTP


	2.	配置 & 编译

mkdir build
cd build
cmake ..
make

	•	这样会同时编译主程序（如 MiniProHTTP 可执行文件）和测试用例（如 test_threadpool）。

	3.	运行测试
	•	若你已在 CMake 里配置了 enable_testing() 并注册了测试，可直接执行：

ctest

或者：

./tests/test_threadpool


	•	你会看到 Google Test 输出：

[==========] Running 2 tests from 1 test suite.
...
[  PASSED  ] 2 tests.

表示线程池的测试通过。

线程池用法示例

main.cpp 中的一个最小示例：

#include "threadpool/threadpool.h"
#include <iostream>
#include <chrono>

int main() {
    ThreadPool pool(4);  // 创建包含4个工作线程的线程池

    // 提交10个任务
    for (int i = 0; i < 10; i++) {
        pool.enqueue([i] {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << "Task " << i << " done in thread "
                      << std::this_thread::get_id() << "\n";
        });
    }

    // 等待2秒，观察输出
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "All tasks submitted.\n";

    return 0;
}

编译并运行后，可以看到每个任务都由不同的工作线程并发执行。

测试：test_threadpool.cpp

下面是一个简化的测试示例（已在 tests/test_threadpool.cpp）：

#include <gtest/gtest.h>
#include "threadpool/threadpool.h"
#include <atomic>
#include <chrono>

TEST(ThreadPoolTest, BasicTaskExecution) {
    ThreadPool pool(4);
    std::atomic<int> counter{0};
    int numTasks = 10;

    for (int i = 0; i < numTasks; i++) {
        pool.enqueue([&counter]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            ++counter;
        });
    }
    // 等一会儿让所有任务执行完
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    EXPECT_EQ(counter.load(), numTasks);
}

TEST(ThreadPoolTest, StopEarly) {
    {
        ThreadPool pool(2);
        for(int i = 0; i < 5; i++){
            pool.enqueue([i]{
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            });
        }
    }
    // 出作用域后 ThreadPool 析构，测试是否能平稳退出
    SUCCEED() << "ThreadPool destructed without crash.";
}

运行此测试可验证：
	•	任务都被正确执行（BasicTaskExecution）
	•	线程池在析构时不会崩溃或死锁（StopEarly）



