#include "threadpool.h"

ThreadPool::ThreadPool(size_t numThreads) : stop_(false) {
    for (size_t i = 0; i < numThreads; ++i) {
        workers_.emplace_back([this]() {
            this->workerThread();
        });
    }
}

ThreadPool::~ThreadPool() {
    stop_ = true; //必须先设置stop_为true，否则线程池析构时，线程还在运行，即使任务队列中还有任务
    condVar_.notify_all(); //唤醒所有线程，让他们退出   
    for (auto &thread : workers_) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

void ThreadPool::enqueue(std::function<void()> task) {
    {
        std::unique_lock<std::mutex> lock(queueMutex_);
        tasks_.push(task);
    }  //出了这个大括号，lock 被析构，mutex 自动释放；如果不是设置这个作用域，就只有等到到函数返回，lock 才被析构，mutex 才自动释放
    condVar_.notify_one();
}

void ThreadPool::workerThread() {
    while (true) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(queueMutex_); //拿到锁才能继续执行下面的代码，否则会阻塞
            condVar_.wait(lock, [this]{ //拿到锁之后，看看任务列表是否为空，或者线程池是否停止
                return stop_ || !tasks_.empty();
            });   //如果任务列表为空，或者线程池停止，则不执行下一行代码，直到有任务或者线程池停止
            if (stop_ && tasks_.empty()) { //   
                return;  //这里当stop_为true，必须保证任务列表为空时，线程才能退出！！！
            }
            task = std::move(tasks_.front());
            tasks_.pop();
        }   //拿到任务lock 被析构，mutex 自动释放
        // 执行任务
        task();
    }
}