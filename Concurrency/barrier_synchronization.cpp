#include <iostream>
#include <thread>
#include <vector>
#include <barrier>

constexpr int THREADS = 4;
std::barrier sync_point(THREADS, []() {
    std::cout << "--- All threads reached phase barrier ---\n";
});

void worker(int id) {
    std::cout << "Thread " << id << " working on Phase 1\n";
    sync_point.arrive_and_wait();
    std::cout << "Thread " << id << " working on Phase 2\n";
}

int main() {
    std::vector<std::thread> workers;
    for (int i = 0; i < THREADS; ++i) {
        workers.emplace_back(worker, i);
    }
    for (auto& w : workers) w.join();
    return 0;
}
