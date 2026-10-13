#include <iostream>
#include <vector>
#include <memory>

class Graphic {
public:
    virtual ~Graphic() = default;
    virtual void draw() = 0;
};

class Dot : public Graphic {
public:
    void draw() override { std::cout << "Drawing Dot\n"; }
};

class CompoundGraphic : public Graphic {
private:
    std::vector<std::unique_ptr<Graphic>> children_;
public:
    void add(std::unique_ptr<Graphic> child) {
        children_.push_back(std::move(child));
    }
    void draw() override {
        for (const auto& child : children_) child->draw();
    }
};

int main() {
    CompoundGraphic group;
    group.add(std::make_unique<Dot>());
    group.add(std::make_unique<Dot>());
    group.draw();
    return 0;
}
