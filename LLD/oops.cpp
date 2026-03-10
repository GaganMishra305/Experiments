#include <bits/stdc++.h>
using namespace std;

/* ABSTRACTION (abstract classes, interfaces)*/
class Parent {
    int data;
    public:
        Parent(int d) : data(d) {}
        virtual void func() = 0;
};

class Child : public Parent { /* INHERITANCE (single, multilevel, hierarchil(single parent), multiple(single child many parents)) */
public:
    Child(): Parent(0) {}

    void func() override{ /* POLYMORPHISM (runtime(method-overriding), compiletime(method-overloadin)) */
        cout << "Child class" << endl;
    }
};




int main() {
    Parent* ch = new Child(); /* ENCAPSULATION */
    ch->func();
}

