#include <bits/stdc++.h>
using namespace std;

void hello_world() {
    cout << "Hello World: " << this_thread::get_id() << endl;
}

int main() {
    cout << "Main thread: " << this_thread::get_id() << endl;

    thread t(hello_world);
    t.join();
}

/*
Why concurrent design?
1. multitaskin
2. performance (i need this)
*/