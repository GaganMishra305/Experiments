// VISITOR: lets you add new operations to existing object without modifying the original class
// Ex: 

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct Circle;
struct Rectangle;

struct Visitor {
	virtual void visit(Circle& c) = 0;
	virtual void visit(Rectangle& r) = 0;
	virtual ~Visitor() = default;
};

struct Shape {
	virtual void accept(Visitor& v) = 0;
	virtual ~Shape() = default;
};

struct Circle : Shape {
	int radius;
	explicit Circle(int r) : radius(r) {}
	void accept(Visitor& v) override { v.visit(*this); }
};

struct Rectangle : Shape {
	int w, h;
	Rectangle(int width, int height) : w(width), h(height) {}
	void accept(Visitor& v) override { v.visit(*this); }
};

struct AreaVisitor : Visitor {
	void visit(Circle& c) override { cout << 3 * c.radius * c.radius << '\n'; }
	void visit(Rectangle& r) override { cout << r.w * r.h << '\n'; }
};

int main() {
	vector<unique_ptr<Shape>> shapes;
	shapes.push_back(make_unique<Circle>(2));
	shapes.push_back(make_unique<Rectangle>(2, 3));
	AreaVisitor visitor;
	for (auto& shape : shapes) shape->accept(visitor);
}
