// STATE: object changes its behavior when its internal state changes
// Ex: any game, any fsm

#include <iostream>
#include <memory>
using namespace std;

struct State { virtual string handle() const = 0; virtual ~State() = default; };
struct Locked : State { string handle() const override { return "Unlock first"; } };
struct Unlocked : State { string handle() const override { return "Open door"; } };

struct Door {
    unique_ptr<State> state = make_unique<Locked>();
    void set(unique_ptr<State> s) { state = move(s); }
    void action() const { cout << state->handle() << '\n'; }
};

int main() {
    Door d;
    d.action();
    d.set(make_unique<Unlocked>());
    d.action();
}
