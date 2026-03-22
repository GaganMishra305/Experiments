// "dont repeat yourself"
// Rule of 3 

#include <iostream>
using namespace std;

int square(int value) {
	return value * value;
}

int main() {
	int a = 2, b = 3, c = 4;
	cout << square(a) << '\n';
	cout << square(b) << '\n';
	cout << square(c) << '\n';
}
