#pragma once
#include <vector>
#include "CartItem.h"
using namespace std;

class Cart {
    vector<CartItem> items;

public:
    void add(Product* product, int quantity) {
        if (quantity > product->getQuantity()) {
            throw runtime_error("Quantity exceeds stock");
        }
        items.push_back({ product, quantity });
    }

    const vector<CartItem>& getItems() const {
        return items;
    }

    bool isEmpty() const {
        return items.empty();
    }

    void clear() {
        items.clear();
    }
};

