#include <iostream>
#include <memory>
#include <vector>

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

class Light {
public:
    void turnOn() { std::cout << "Light is ON\n"; }
    void turnOff() { std::cout << "Light is OFF\n"; }
};

class LightOnCommand : public Command {
private:
    Light& light_;
public:
    LightOnCommand(Light& light) : light_(light) {}
    void execute() override { light_.turnOn(); }
};

int main() {
    Light light;
    LightOnCommand cmd(light);
    cmd.execute();
    return 0;
}
