// Facade Pattern
#include <iostream>
using namespace std;

struct CPU { void start() { cout << "CPU start\n"; } };
struct Memory { void load() { cout << "Memory load\n"; } };
struct Disk { void read() { cout << "Disk read\n"; } };

struct ComputerFacade {
    CPU cpu; Memory memory; Disk disk;
    void boot() { cpu.start(); memory.load(); disk.read(); }
};

int main() {
    ComputerFacade c;
    c.boot();
}
