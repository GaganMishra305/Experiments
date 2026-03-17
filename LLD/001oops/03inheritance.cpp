/*
INHERITANCE allows to:
    1. inherit (all non-private properties)
    2. extend
    3. override
*/

/*
Only C++ and python allow multiple-inheritance due to the DIAMOND problem.
SOLN:
    C++ handles this with virtual inheritance, which is complex and error-prone. Python handles it with the Method Resolution Order (MRO), a well-defined algorithm (C3 linearization) that determines which parent's method takes priority. Java and C# sidestep the problem entirely by only allowing single class inheritance, you can implement multiple interfaces, but extend only one class.
*/

/*
USED:  is-a relationship
AVOID: has-a relationship
*/

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class BankAccount {
protected:
    string ownerName;
    string accountNumber;
    double balance;

public:
    BankAccount(const string& ownerName, const string& accountNumber,
                double balance): 
                    ownerName(ownerName), accountNumber(accountNumber), balance(balance) {    }

    virtual ~BankAccount() {}

    bool deposit(double amount) {
        if(amount <= 0) return false;
        balance += amount;
        return true;
    }

    virtual bool withdraw(double amount) {
        if(balance < amount) return false;
        balance -= amount;
        return true;
    }

    void displayAccount() {
        // Hint: use printf("$%.2f", balance) for formatting
        char buf[32];
        sprintf(buf, "$%.2f", balance);
        cout << ownerName << " (" << accountNumber << ") | Balance: "
             << buf << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(const string& ownerName, const string& accountNumber,
                   double balance, double interestRate)
        : BankAccount(ownerName, accountNumber, balance) {
        this->interestRate = interestRate;
    }

    bool withdraw(double amount) override {
       if((balance - amount) < 100) return false;
       balance -= amount;
       return true;
    }

    void applyInterest() {
        balance += (balance * interestRate / 100);
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(const string& ownerName, const string& accountNumber,
                    double balance, double overdraftLimit)
        : BankAccount(ownerName, accountNumber, balance) {
        this->overdraftLimit = overdraftLimit;
    }

    bool withdraw(double amount) override {
       if((balance + overdraftLimit) < amount) return false;
        balance -= amount;
        return true;

    }
};

int main() {
    SavingsAccount savings("Alice", "SAV-001", 1000, 2.0);
    savings.displayAccount();
    cout << "Withdraw $950: " << (savings.withdraw(950) ? "true" : "false") << endl;
    savings.applyInterest();
    savings.displayAccount();

    cout << endl;

    CheckingAccount checking("Bob", "CHK-002", 500, 300);
    checking.displayAccount();
    cout << "Withdraw $700: " << (checking.withdraw(700) ? "true" : "false") << endl;
    checking.displayAccount();

    return 0;
}
