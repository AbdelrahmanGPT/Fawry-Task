#pragma once
#include "Shippable.h"
#include "Product.h"

class ShippableProduct : public Shippable {
    const Product* product;
    int count;

public:
    ShippableProduct(const Product* p, int c) : product(p), count(c) {}

    string getName() const override {
        return to_string(count) + "x " + product->getName() + " " +
            to_string(int(product->getWeight() * 1000)) + "g";
    }

    double getWeight() const override {
        return product->getWeight() * count;
    }
};


