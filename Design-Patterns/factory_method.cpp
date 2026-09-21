#include <iostream>
#include <memory>

class Transport {
public:
    virtual ~Transport() = default;
    virtual void deliver() = 0;
};

class Truck : public Transport {
public:
    void deliver() override { std::cout << "Delivering by land in a truck\n"; }
};

class Ship : public Transport {
public:
    void deliver() override { std::cout << "Delivering by sea in a container ship\n"; }
};

class Logistics {
public:
    virtual ~Logistics() = default;
    virtual std::unique_ptr<Transport> createTransport() = 0;
    void planDelivery() {
        auto transport = createTransport();
        transport->deliver();
    }
};

class RoadLogistics : public Logistics {
public:
    std::unique_ptr<Transport> createTransport() override {
        return std::make_unique<Truck>();
    }
};

int main() {
    RoadLogistics road;
    road.planDelivery();
    return 0;
}
