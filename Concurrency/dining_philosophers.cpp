#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

constexpr int NUM_PHILOSOPHERS = 5;
std::mutex forks[NUM_PHILOSOPHERS];

void philosopher(int id) {
    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;

    for (int i = 0; i < 3; ++i) {
        // Thinking
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        // Pick up both forks avoiding deadlock (std::lock locks both atomically)
        std::lock(forks[left], forks[right]);
        std::lock_guard<std::mutex> lock_left(forks[left], std::adopt_lock);
        std::lock_guard<std::mutex> lock_right(forks[right], std::adopt_lock);

        // Eating
        std::cout << "Philosopher " << id << " is eating (round " << i + 1 << ")
";
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
    }
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        threads.emplace_back(philosopher, i);
    }
    for (auto& t : threads) {
        t.join();
    }
    std::cout << "All philosophers finished eating.
";
    return 0;
}
