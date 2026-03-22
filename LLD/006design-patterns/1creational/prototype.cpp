// PROTOTYPE: new objects by cloning other objects
// Ex: making enemies in a game (shallow-copy vs deep-copy)
    
#include <iostream>
#include <memory>
using namespace std;

struct Shape {
    virtual unique_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

struct Circle : Shape {
    int radius;
    explicit Circle(int r) : radius(r) {}
    unique_ptr<Shape> clone() const override { return make_unique<Circle>(*this); }
    void draw() const override { cout << "Circle r=" << radius << '\n'; }
};

int main() {
    unique_ptr<Shape> a = make_unique<Circle>(7);
    unique_ptr<Shape> b = a->clone();
    a->draw();
    b->draw();
}
