// MEDIATOR: encapsulates how a set of objects interact
// Ex: chat room

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct User;

struct ChatRoom {
	vector<User*> users;
	void join(User* user) { users.push_back(user); }
	void send(const string& from, const string& message);
};

struct User {
	string name;
	ChatRoom& room;
	User(string n, ChatRoom& r) : name(move(n)), room(r) {}
	void send(const string& message) { room.send(name, message); }
	void receive(const string& from, const string& message) {
		cout << from << " -> " << name << ": " << message << '\n';
	}
};

void ChatRoom::send(const string& from, const string& message) {
	for (User* user : users) {
		if (user->name != from) user->receive(from, message);
	}
}

int main() {
	ChatRoom room;
	User a("A", room), b("B", room);
	room.join(&a);
	room.join(&b);
	a.send("hi");
}