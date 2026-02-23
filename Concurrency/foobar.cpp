#include <bits/stdc++.h>
using namespace std;

class FooBar {
private:
    int n;
    bool foodone;
    mutex mtx;
    condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
        foodone = false;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
        	// printFoo() outputs "foo". Do not change or remove this line.
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] {return !foodone;});
        	printFoo();
            foodone = true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
        	// printBar() outputs "bar". Do not change or remove this line.
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] {return foodone;});
        	printBar();
            foodone = false;
            cv.notify_all();
        }
    }
};
