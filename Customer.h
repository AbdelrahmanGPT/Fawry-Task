#pragma once
#include <string>
#include <stdexcept>
using namespace std;

class Customer {
    string name;
    double balance;

public:
    Customer(string n, double b) : name(n), balance(b) {}

    string getName() const { return name; }
    double getBalance() const { return balance; }

    void deduct(double amount) {
        if (amount > balance) throw runtime_error("Insufficient balance");
        balance -= amount;
    }

    double getRemainingBalance() const {
        return balance;
    }
};

