#pragma once
#include <string>
#include <stdexcept>
using namespace std;

class Product {
protected:
    string name;
    double price;
    int quantity;
    bool isExpirable;
    bool isShippable;
    double weight;

public:
    Product(string n, double p, int q, bool exp, bool ship, double w = 0.0)
        : name(n), price(p), quantity(q), isExpirable(exp), isShippable(ship), weight(w) {
    }

    virtual ~Product() = default;

    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    bool getIsExpirable() const { return isExpirable; }
    bool getIsShippable() const { return isShippable; }
    double getWeight() const { return weight; }

    void reduceQuantity(int q) {
        if (q > quantity) throw runtime_error("Not enough stock");
        quantity -= q;
    }

    virtual bool isExpired() const {
        return isExpirable; // simplified for demo
    }
};

