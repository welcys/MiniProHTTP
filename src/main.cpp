#include <iostream>
#include "threadpool/threadpool.h"
#include <chrono>

int main() {
    ThreadPool pool(4);
    for(int i = 0; i < 10; i++) {
        pool.enqueue([i]{
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << "Task " << i << " done in thread "
                      << std::this_thread::get_id() << std::endl;
        });
    }
    // 加个sleep，让任务都执行完(或者等池子析构)
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "All tasks submitted\n";
    return 0;
}
