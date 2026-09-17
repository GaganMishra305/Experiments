#include <iostream>
#include <shared_mutex>
#include <thread>
#include <vector>
#include <chrono>

class ThreadSafeCounter {
private:
    mutable std::shared_mutex mutex_;
    int value_ = 0;

public:
    int get() const {
        std::shared_lock<std::shared_mutex> lock(mutex_);
        return value_;
    }

    void increment() {
        std::unique_lock<std::shared_mutex> lock(mutex_);
        ++value_;
    }
};

int main() {
    ThreadSafeCounter counter;
    std::vector<std::thread> readers;
    std::vector<std::thread> writers;

    for (int i = 0; i < 3; ++i) {
        writers.emplace_back([&counter, i]() {
            counter.increment();
            std::cout << "Writer " << i << " incremented counter
";
        });
    }

    for (int i = 0; i < 5; ++i) {
        readers.emplace_back([&counter, i]() {
            int val = counter.get();
            std::cout << "Reader " << i << " read counter = " << val << "
";
        });
    }

    for (auto& w : writers) w.join();
    for (auto& r : readers) r.join();

    std::cout << "Final value: " << counter.get() << "
";
    return 0;
}
