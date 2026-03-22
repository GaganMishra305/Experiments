// SINGLETON: when a single-instance is needed at one tiem
// Ex: thread pools, caches, loggers

#include <iostream>
using namespace std;

class Logger {
    Logger() = default;
public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    static Logger& instance() { static Logger x; return x; }
    void log(const string& msg) { cout << "[LOG] " << msg << '\n'; }
};

int main() {
    Logger::instance().log("start");
    Logger::instance().log("finish");
}
