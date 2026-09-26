#include <iostream>
#include <memory>

class Beverage {
public:
    virtual ~Beverage() = default;
    virtual std::string getDescription() = 0;
    virtual double cost() = 0;
};

class Espresso : public Beverage {
public:
    std::string getDescription() override { return "Espresso"; }
    double cost() override { return 1.99; }
};

class MilkDecorator : public Beverage {
private:
    std::unique_ptr<Beverage> beverage_;
public:
    MilkDecorator(std::unique_ptr<Beverage> b) : beverage_(std::move(b)) {}
    std::string getDescription() override { return beverage_->getDescription() + ", Milk"; }
    double cost() override { return beverage_->cost() + 0.50; }
};

int main() {
    std::unique_ptr<Beverage> coffee = std::make_unique<Espresso>();
    coffee = std::make_unique<MilkDecorator>(std::move(coffee));
    std::cout << coffee->getDescription() << " : $" << coffee->cost() << "\n";
    return 0;
}
