#include <iostream>
#include <atomic>
#include <thread>

template <typename T>
class LockFreeStack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(std::move(val)), next(nullptr) {}
    };
    std::atomic<Node*> head_{nullptr};

public:
    void push(T val) {
        Node* new_node = new Node(std::move(val));
        new_node->next = head_.load(std::memory_order_relaxed);
        while (!head_.compare_exchange_weak(new_node->next, new_node,
                                            std::memory_order_release,
                                            std::memory_order_relaxed)) {}
    }
};

int main() {
    LockFreeStack<int> s;
    s.push(10);
    s.push(20);
    std::cout << "Pushed elements to lock-free stack\n";
    return 0;
}
