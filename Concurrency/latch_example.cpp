#include <iostream>
#include <thread>
#include <vector>
#include <latch>

constexpr int NUM_TASKS = 3;
std::latch work_done(NUM_TASKS);

void doInitWork(int id) {
    std::cout << "Initialization task " << id << " completed\n";
    work_done.count_down();
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < NUM_TASKS; ++i) {
        threads.emplace_back(doInitWork, i);
    }
    work_done.wait();
    std::cout << "All init tasks done! Server ready to accept traffic.\n";
    for (auto& t : threads) t.join();
    return 0;
}
