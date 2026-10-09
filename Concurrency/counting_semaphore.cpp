#include <iostream>
#include <thread>
#include <vector>
#include <semaphore>
#include <chrono>

std::counting_semaphore<3> pool_sem(3);

void worker(int id) {
    std::cout << "Worker " << id << " waiting for resource\n";
    pool_sem.acquire();
    std::cout << "Worker " << id << " acquired resource (working...)\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(60));
    std::cout << "Worker " << id << " releasing resource\n";
    pool_sem.release();
}

int main() {
    std::vector<std::thread> workers;
    for (int i = 0; i < 6; ++i) {
        workers.emplace_back(worker, i);
    }
    for (auto& w : workers) w.join();
    return 0;
}
