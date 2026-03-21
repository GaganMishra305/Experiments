// Adapter Pattern
#include <iostream>
using namespace std;

struct OldPrinter { void printOld(const string& s) { cout << "Old: " << s << '\n'; } };
struct Printer { virtual void print(const string& s) = 0; virtual ~Printer() = default; };

struct PrinterAdapter : Printer {
    OldPrinter old;
    void print(const string& s) override { old.printOld(s); }
};

int main() {
    PrinterAdapter p;
    p.print("hello");
}
