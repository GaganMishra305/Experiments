// CHAIN-of-RESPONSIBLITY: request is passed along a chain of handlers
// Ex: middleware architecture

#include <iostream>
#include <memory>
using namespace std;

struct Handler {
	shared_ptr<Handler> next;
	virtual bool handle(int value) {
		if (next) return next->handle(value);
		return false;
	}
	virtual ~Handler() = default;
};

struct EvenHandler : Handler {
	bool handle(int value) override {
		if (value % 2 == 0) {
			cout << "EvenHandler\n";
			return true;
		}
		return Handler::handle(value);
	}
};

struct PositiveHandler : Handler {
	bool handle(int value) override {
		if (value > 0) {
			cout << "PositiveHandler\n";
			return true;
		}
		return Handler::handle(value);
	}
};

int main() {
	auto even = make_shared<EvenHandler>();
	auto positive = make_shared<PositiveHandler>();
	even->next = positive;
	even->handle(5);
	even->handle(8);
}
