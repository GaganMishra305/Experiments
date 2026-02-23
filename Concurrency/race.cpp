#include <bits/stdc++.h>
using namespace std;

int arr[100];
mutex mtx;

void read(int idx) {
    cout << "READ: " << arr[idx] << endl;
}

void write(int data, int idx) {
    lock_guard<mutex> lock(mtx);
    arr[idx] = data;
}

int main() {
    thread t1(static_cast<void(*)(int)>(read), 0);
    thread t2(static_cast<void(*)(int, int)>(write), 42, 0);
    t1.join();
    t2.join();
}

/*
lock_guard unlocks after the scope
unique_lock can be unlocked anywhere
shared_lock a number of threads can interact unless there is another different thread lock ... essentially allowing multiple parallel reads and avoiding multiple write
*/

/*
GRANULARITY OF LOCKING: we want locks to be granular as they make the code synchronous (otherwise pura code synchronous hojayega)
*/
