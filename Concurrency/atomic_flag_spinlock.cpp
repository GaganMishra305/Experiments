#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

class Spinlock {
private:
    std::atomic_flag flag_ = ATOMIC_FLAG_INIT;
public:
    void lock() {
        while (flag_.test_and_set(std::memory_order_acquire)) {
            // Busy wait spin
        }
    }
    void unlock() {
        flag_.clear(std::memory_order_release);
    }
};

int main() {
    Spinlock spin;
    int counter = 0;
    std::vector<std::thread> threads;
    for (int i = 0; i < 4; ++i) {
        threads.emplace_back([&]() {
            for (int j = 0; j < 1000; ++j) {
                spin.lock();
                ++counter;
                spin.unlock();
            }
        });
    }
    for (auto& t : threads) t.join();
    std::cout << "Counter: " << counter << "\n";
    return 0;
}
