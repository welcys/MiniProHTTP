#pragma once
#include <functional>
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>

class ThreadPool {
public:

  explicit ThreadPool(size_t numThreads);
  ~ThreadPool();

  // 禁用拷贝，防止线程池被拷贝
  ThreadPool(const ThreadPool&) = delete;
  ThreadPool& operator=(const ThreadPool&) = delete; // 禁用赋值操作，防止线程池被赋值

  // 添加任务到任务队列
  void enqueue(std::function<void()> task);

private:
  // 工作线程的运行函数
  void workerThread();

  // 成员变量
  std::vector<std::thread> workers_; // 工作线程的容器
  std::queue<std::function<void()>> tasks_; // 任务队列

  std::mutex queueMutex_; // 互斥锁,用于保护任务队列，防止多个线程同时访问任务队列
  std::condition_variable condVar_; // 条件变量,用于线程间的同步，当任务队列为空时，线程等待，当有任务时，唤醒线程
  std::atomic<bool> stop_; // 用于在析构或其他地方通知线程停止
};