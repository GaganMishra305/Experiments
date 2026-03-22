// TEMPLATE METHOD: skeleton of an algo as the base class, then the subclassses can override specific parts
// Ex: online order processing

#include <iostream>
using namespace std;

struct OrderProcessor {
	void process() {
		selectItem();
		pay();
		deliver();
	}
	virtual void selectItem() = 0;
	virtual void pay() = 0;
	virtual void deliver() = 0;
	virtual ~OrderProcessor() = default;
};

struct OnlineOrder : OrderProcessor {
	void selectItem() override { cout << "select\n"; }
	void pay() override { cout << "pay-online\n"; }
	void deliver() override { cout << "ship\n"; }
};

int main() {
	OnlineOrder order;
	order.process();
}
