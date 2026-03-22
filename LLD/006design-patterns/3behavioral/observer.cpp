// OBSERVER: change in the state of parent object notifies mutiple observers
// Ex: notficiation system

#include <iostream>
#include <vector>
using namespace std;

struct Observer { virtual void update(int v) = 0; virtual ~Observer() = default; };
struct Subject {
    vector<Observer*> obs;
    void attach(Observer* o) { obs.push_back(o); }
    void notify(int v) { for (auto* o : obs) o->update(v); }
};
struct Screen : Observer { void update(int v) override { cout << "Screen: " << v << '\n'; } };
struct Log : Observer { void update(int v) override { cout << "Log: " << v << '\n'; } };

int main() {
    Subject s; Screen a; Log b;
    s.attach(&a); s.attach(&b);
    s.notify(42);
}
