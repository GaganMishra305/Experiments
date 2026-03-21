// A class should do one thing, and do it well.

#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <string>

using namespace std;

class InventoryManager {
    unordered_map<string, int> stock;
public:
    InventoryManager() {
        stock["LAPTOP"] = 10;
        stock["PHONE"] = 25;
        stock["TABLET"] = 15;
    }

    bool checkStock(const string& productId, int quantity) {
        auto it = stock.find(productId);
        return it != stock.end() && it->second >= quantity;
    }

    void reduceStock(const string& productId, int quantity) {
        stock[productId] -= quantity;
    }
};

class NotificationService {
public:
    void sendOrderConfirmation(const string& customerEmail,
                               const string& orderId, double total) {
        cout << fixed << setprecision(1);
        cout << "Email to " << customerEmail << ": Order " << orderId
             << " confirmed. Total: $" << total << endl;
    }
};

class OrderProcessor {
    InventoryManager& inventoryManager;
    NotificationService& notificationService;
    int orderCounter = 0;
public:
    OrderProcessor(InventoryManager& inv, NotificationService& notif)
        : inventoryManager(inv), notificationService(notif) {}

    void placeOrder(const string& productId, int quantity,
                    const string& customerEmail) {
        if (!inventoryManager.checkStock(productId, quantity)) {
            cout << "Insufficient stock for " << productId << endl;
            return;
        }
        inventoryManager.reduceStock(productId, quantity);
        double total = quantity * 100.0;
        orderCounter++;
        string orderId = "ORD-" + to_string(orderCounter);
        notificationService.sendOrderConfirmation(customerEmail, orderId, total);
    }
};

int main() {
    InventoryManager inventory;
    NotificationService notifications;
    OrderProcessor processor(inventory, notifications);
    processor.placeOrder("LAPTOP", 2, "alice@example.com");
    return 0;
}
