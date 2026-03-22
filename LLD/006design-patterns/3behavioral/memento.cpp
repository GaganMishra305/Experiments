// MEMENTO: lets you capture internal state of a object, so you ccan resconstruct it later
// Ex: undo operation

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Memento {
	string state;
	explicit Memento(string s) : state(move(s)) {}
};

struct Editor {
	string text;
	void type(const string& value) { text += value; }
	Memento save() const { return Memento(text); }
	void restore(const Memento& m) { text = m.state; }
};

int main() {
	Editor editor;
	vector<Memento> history;
	editor.type("A");
	history.push_back(editor.save());
	editor.type("B");
	cout << editor.text << '\n';
	editor.restore(history.back());
	cout << editor.text << '\n';
}
