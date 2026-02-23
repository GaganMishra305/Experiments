#include <bits/stdc++.h>
using namespace std;

queue<string> q;

void consumer() {
    while(1) {
        if(!q.empty()) {
            cout << "READ: " << q.front();
            q.pop();
        }
    }
}

void producer(string msg) {
    q.push(msg);
}

void input_reader() {
    while(1) {
        cout << "ENTER: ";
        string x; cin >> x;
        producer(x);
        cout << endl;
    }
}

int main() {
    thread t1(input_reader);
    thread t2(consumer);

    t1.join();
    t2.join();
}

/*
condition-variable notifies the consumer about the shared value
*/
