// DECORATOR: dynamically add new behaviors on top of a object
// Ex: Text renderer(you can bold it, underline it, change size and color)

#include <iostream>
#include <memory>
using namespace std;

struct Coffee { virtual int cost() const = 0; virtual ~Coffee() = default; };
struct BasicCoffee : Coffee { int cost() const override { return 50; } };
struct Milk : Coffee {
    unique_ptr<Coffee> base;
    explicit Milk(unique_ptr<Coffee> c) : base(move(c)) {}
    int cost() const override { return base->cost() + 20; }
};

int main() {
    unique_ptr<Coffee> c = make_unique<Milk>(make_unique<BasicCoffee>());
    cout << c->cost() << '\n';
}
