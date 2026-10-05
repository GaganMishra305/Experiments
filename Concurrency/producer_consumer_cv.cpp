#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv_empty;
std::condition_variable cv_full;
constexpr size_t CAPACITY = 5;

void producer(int n) {
    for (int i = 0; i < n; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv_full.wait(lock, []() { return buffer.size() < CAPACITY; });
        buffer.push(i);
        std::cout << "Produced item: " << i << "\n";
        cv_empty.notify_one();
    }
}

void consumer(int n) {
    for (int i = 0; i < n; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv_empty.wait(lock, []() { return !buffer.empty(); });
        int val = buffer.front();
        buffer.pop();
        std::cout << "Consumed item: " << val << "\n";
        cv_full.notify_one();
    }
}

int main() {
    std::thread p(producer, 10);
    std::thread c(consumer, 10);
    p.join();
    c.join();
    return 0;
}
