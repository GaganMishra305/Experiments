// "you arent gonna need it"

#include <iostream>
#include <string>
using namespace std;

struct User {
	string name;
	explicit User(string n) : name(move(n)) {}
	void greet() const { cout << "Hello " << name << '\n'; }
};

int main() {
	User user("Gagan");
	user.greet();
}
