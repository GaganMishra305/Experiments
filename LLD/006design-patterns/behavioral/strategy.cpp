// Strategy Pattern
#include <iostream>
#include <memory>
using namespace std;

struct Operation { virtual int run(int a, int b) const = 0; virtual ~Operation() = default; };
struct Add : Operation { int run(int a, int b) const override { return a + b; } };
struct Multiply : Operation { int run(int a, int b) const override { return a * b; } };

struct Context {
    unique_ptr<Operation> op;
    explicit Context(unique_ptr<Operation> o) : op(move(o)) {}
    int execute(int a, int b) const { return op->run(a, b); }
};

int main() {
    Context c1(make_unique<Add>()), c2(make_unique<Multiply>());
    cout << c1.execute(2, 3) << '\n' << c2.execute(2, 3) << '\n';
}
