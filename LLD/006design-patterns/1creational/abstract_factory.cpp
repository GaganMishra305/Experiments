// ABSTRACT-FACTORY: interface to create family of new objects
// Ex: UI-libraries

#include <iostream>
#include <memory>
using namespace std;

struct Button { virtual string draw() const = 0; virtual ~Button() = default; };
struct Checkbox { virtual string check() const = 0; virtual ~Checkbox() = default; };
struct WinButton : Button { string draw() const override { return "Windows Button"; } };
struct MacButton : Button { string draw() const override { return "Mac Button"; } };
struct WinCheckbox : Checkbox { string check() const override { return "Windows Checkbox"; } };
struct MacCheckbox : Checkbox { string check() const override { return "Mac Checkbox"; } };

struct GUIFactory {
    virtual unique_ptr<Button> createButton() const = 0;
    virtual unique_ptr<Checkbox> createCheckbox() const = 0;
    virtual ~GUIFactory() = default;
};
struct WinFactory : GUIFactory {
    unique_ptr<Button> createButton() const override { return make_unique<WinButton>(); }
    unique_ptr<Checkbox> createCheckbox() const override { return make_unique<WinCheckbox>(); }
};
struct MacFactory : GUIFactory {
    unique_ptr<Button> createButton() const override { return make_unique<MacButton>(); }
    unique_ptr<Checkbox> createCheckbox() const override { return make_unique<MacCheckbox>(); }
};

int main() {
    unique_ptr<GUIFactory> f = make_unique<WinFactory>();
    cout << f->createButton()->draw() << " | " << f->createCheckbox()->check() << '\n';
    f = make_unique<MacFactory>();
    cout << f->createButton()->draw() << " | " << f->createCheckbox()->check() << '\n';
}