#include <iostream>
#include <vector>
#include <algorithm>

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void onNotify(const std::string& message) = 0;
};

class Subject {
private:
    std::vector<IObserver*> observers_;
public:
    void subscribe(IObserver* obs) { observers_.push_back(obs); }
    void notify(const std::string& message) {
        for (auto* obs : observers_) obs->onNotify(message);
    }
};

class ConcreteObserver : public IObserver {
private:
    std::string name_;
public:
    ConcreteObserver(std::string name) : name_(std::move(name)) {}
    void onNotify(const std::string& message) override {
        std::cout << name_ << " received: " << message << "\n";
    }
};

int main() {
    Subject subject;
    ConcreteObserver o1("Observer-1");
    ConcreteObserver o2("Observer-2");
    subject.subscribe(&o1);
    subject.subscribe(&o2);
    subject.notify("State changed to ACTIVE");
    return 0;
}
