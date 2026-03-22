// Iterator Pattern
#include <iostream>
#include <vector>
using namespace std;

class NumberCollection {
    vector<int> data;
public:
    NumberCollection(initializer_list<int> x) : data(x) {}
    auto begin() const { return data.begin(); }
    auto end() const { return data.end(); }
};

int main() {
    NumberCollection c{1, 2, 3, 4};
    for (int x : c) cout << x << ' ';
    cout << '\n';
}
