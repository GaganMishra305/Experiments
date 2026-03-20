// "owns-a" relationship
// whole is destroyed then the parts ARE destroyed (company and employee)

#include <bits/stdc++.h>
using namespace std;

class LineItem {
private:
    string productName;
    int quantity;
    double unitPrice;

public:
    LineItem(const string& productName, int quantity, double unitPrice)
        : productName(productName), quantity(quantity), unitPrice(unitPrice) {}

    double getSubtotal() const {
        return quantity * unitPrice;
    }

    string getProductName() const {
        return productName;
    }

    void describe() const {
        cout << productName << " x" << quantity
             << " @ $" << unitPrice
             << " = $" << getSubtotal() << endl;
    }
};

class Order {
private:
    string orderId;
    vector<LineItem> lineItems;

public:
    Order(const string& orderId) : orderId(orderId) {}

    void addItem(const string& product, int quantity, double unitPrice) {
        lineItems.emplace_back(product, quantity, unitPrice);
    }

    void removeItem(const string& product) {
        lineItems.erase(
            remove_if(lineItems.begin(), lineItems.end(),
                [&](const LineItem& item) {
                    return item.getProductName() == product;
                }),
            lineItems.end());
    }

    double getTotal() const {
        double total = 0;
        for (const auto& item : lineItems) {
            total += item.getSubtotal();
        }
        return total;
    }

    void printReceipt() const {
        cout << "Order: " << orderId << endl;
        for (const auto& item : lineItems) {
            item.describe();
        }
        cout << "Total: $" << getTotal() << endl;
    }
};

int main() {
    Order order("ORD-1001");
    order.addItem("Wireless Mouse", 2, 29.99);
    order.addItem("USB-C Cable", 3, 9.99);
    order.addItem("Laptop Stand", 1, 49.99);

    order.printReceipt();

    // When order goes out of scope, all LineItems are destroyed
    // automatically (RAII). No manual cleanup needed.

    return 0;
}
