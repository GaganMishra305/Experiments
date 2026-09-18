#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <vector>

template <typename T>
class ThreadSafeQueue {
private:
    std::queue<T> queue_;
    mutable std::mutex mutex_;
    std::condition_variable cv_;

public:
    void push(T value) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(std::move(value));
        cv_.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this]() { return !queue_.empty(); });
        T val = std::move(queue_.front());
        queue_.pop();
        return val;
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.empty();
    }
};

int main() {
    ThreadSafeQueue<int> q;
    std::thread producer([&q]() {
        for (int i = 1; i <= 5; ++i) {
            q.push(i);
            std::cout << "Produced: " << i << "
";
        }
    });

    std::thread consumer([&q]() {
        for (int i = 1; i <= 5; ++i) {
            int val = q.pop();
            std::cout << "Consumed: " << val << "
";
        }
    });

    producer.join();
    consumer.join();
    return 0;
}
