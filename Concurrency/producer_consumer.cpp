#include <bits/stdc++.h>
using namespace std;

queue<string> q;
mutex mtx;
condition_variable cv;

void consumer() {
    while(1) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []() { return !q.empty(); });
        
        cout << "READ: " << q.front() << endl;
        q.pop();
    }
}

void producer(string msg) {
    {
        unique_lock<mutex> lock(mtx);
        q.push(msg);
    }
    cv.notify_one();
}

void input_reader() {
    while(1) {
        cout << "ENTER: ";
        string x; cin >> x;
        producer(x);
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
mutex protects the queue from race conditions
wait() releases lock, sleeps, and reacquires lock when notified
*/
