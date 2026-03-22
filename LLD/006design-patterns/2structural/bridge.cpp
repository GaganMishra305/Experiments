// BRIDGE: decouple an abstraction with its implementation
// Ex: cross-platform application

#include <iostream>
#include <memory>
using namespace std;

struct Device { virtual string on() const = 0; virtual ~Device() = default; };
struct TV : Device { string on() const override { return "TV on"; } };
struct Radio : Device { string on() const override { return "Radio on"; } };

struct Remote {
    unique_ptr<Device> device;
    explicit Remote(unique_ptr<Device> d) : device(move(d)) {}
    void pressPower() const { cout << device->on() << '\n'; }
};

int main() {
    Remote r1(make_unique<TV>()), r2(make_unique<Radio>());
    r1.pressPower();
    r2.pressPower();
}
