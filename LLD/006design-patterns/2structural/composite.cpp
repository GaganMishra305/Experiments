// COMPOSITE: allows us to treat individual objects and their compositions equally
// Ex: a tree

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct Node { virtual int value() const = 0; virtual ~Node() = default; };
struct Leaf : Node { int x; explicit Leaf(int v): x(v) {} int value() const override { return x; } };
struct Group : Node {
    vector<unique_ptr<Node>> children;
    void add(unique_ptr<Node> n) { children.push_back(move(n)); }
    int value() const override { int s = 0; for (auto& c : children) s += c->value(); return s; }
};

int main() {
    auto g = make_unique<Group>();
    g->add(make_unique<Leaf>(3));
    g->add(make_unique<Leaf>(4));
    cout << g->value() << '\n';
}
