#include <iostream>
#include <mutex>
#include <thread>

class Singleton {
private:
    Singleton() { std::cout << "Singleton initialized\n"; }
    ~Singleton() = default;

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Meyer's Singleton: guaranteed thread-safe in C++11 and beyond
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    void doWork() {
        std::cout << "Doing work from thread: " << std::this_thread::get_id() << "\n";
    }
};

int main() {
    std::thread t1([]() { Singleton::getInstance().doWork(); });
    std::thread t2([]() { Singleton::getInstance().doWork(); });
    t1.join();
    t2.join();
    return 0;
}
