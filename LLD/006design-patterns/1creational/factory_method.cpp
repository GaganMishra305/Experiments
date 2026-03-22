// FACTORY: returns instance of object depedning on the type
// Ex: document-export system

#include <iostream>
#include <memory>
using namespace std;

struct Product { virtual string use() const = 0; virtual ~Product() = default; };
struct Car : Product { string use() const override { return "Drive car"; } };
struct Bike : Product { string use() const override { return "Ride bike"; } };

struct Creator { virtual unique_ptr<Product> create() const = 0; virtual ~Creator() = default; };
struct CarFactory : Creator { unique_ptr<Product> create() const override { return make_unique<Car>(); } };
struct BikeFactory : Creator { unique_ptr<Product> create() const override { return make_unique<Bike>(); } };

int main() {
    unique_ptr<Creator> c = make_unique<CarFactory>();
    cout << c->create()->use() << '\n';
    c = make_unique<BikeFactory>();
    cout << c->create()->use() << '\n';
}