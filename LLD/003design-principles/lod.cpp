// "law of demeter"
// only talk to your immediate friends

#include <iostream>
using namespace std;

struct Wallet {
	int balance;
	explicit Wallet(int amount) : balance(amount) {}
	bool pay(int amount) {
		if (amount > balance) return false;
		balance -= amount;
		return true;
	}
};

struct Customer {
	Wallet wallet;
	explicit Customer(int amount) : wallet(amount) {}
	bool pay(int amount) { return wallet.pay(amount); }
};

struct Shop {
	bool checkout(Customer& customer, int amount) {
		return customer.pay(amount);
	}
};

int main() {
	Customer customer(100);
	Shop shop;
	cout << shop.checkout(customer, 30) << '\n';
	cout << shop.checkout(customer, 80) << '\n';
}
