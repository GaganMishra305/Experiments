// Command Pattern
#include <iostream>
#include <memory>
using namespace std;

struct Light { void on() { cout << "Light on\n"; } void off() { cout << "Light off\n"; } };
struct Command { virtual void execute() = 0; virtual ~Command() = default; };
struct OnCommand : Command { Light& l; explicit OnCommand(Light& x) : l(x) {} void execute() override { l.on(); } };
struct OffCommand : Command { Light& l; explicit OffCommand(Light& x) : l(x) {} void execute() override { l.off(); } };

int main() {
    Light l;
    unique_ptr<Command> c1 = make_unique<OnCommand>(l), c2 = make_unique<OffCommand>(l);
    c1->execute();
    c2->execute();
}
