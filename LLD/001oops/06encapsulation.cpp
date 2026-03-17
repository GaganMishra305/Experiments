/*
Encapsulation = Data hiding + Controlled access
*/
#include <iostream>
#include <string>

class PaymentProcessor {
private:
    std::string cardNumber;
    double amount;

    std::string maskCardNumber(const std::string& cardNumber) {
        return "****-****-****-" + cardNumber.substr(cardNumber.length() - 4);
    }

public:
    PaymentProcessor(const std::string& cardNumber, double amount)
        : cardNumber(maskCardNumber(cardNumber)), amount(amount) {}

    void processPayment() {
        std::cout << "Processing payment of $" << amount
                  << " for card " << cardNumber << std::endl;
    }
};

int main() {
    PaymentProcessor payment("1234567812345678", 250.00);
    payment.processPayment();
    return 0;
}

