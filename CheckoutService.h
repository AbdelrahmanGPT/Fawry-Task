#pragma once
#include <iostream>
#include "Cart.h"
#include "Customer.h"
#include "ShippingService.h"
#include "ShippableProduct.h"

class CheckoutService {
public:
    static void checkout(Customer& customer, Cart& cart) {
        if (cart.isEmpty()) throw runtime_error("Cart is empty");

        vector<Shippable*> shippingItems;
        double subtotal = 0;

        for (auto& item : cart.getItems()) {
            Product* p = item.product;
            int q = item.quantity;

            if (p->isExpired()) throw runtime_error(p->getName() + " is expired.");
            if (p->getQuantity() < q) throw runtime_error("Not enough stock for " + p->getName());

            subtotal += p->getPrice() * q;

            if (p->getIsShippable()) {
                shippingItems.push_back(new ShippableProduct(p, q));
            }
        }

        double shippingFee = shippingItems.empty() ? 0 : 30;
        double total = subtotal + shippingFee;

        if (customer.getBalance() < total) throw runtime_error("Insufficient customer balance");

        // Shipment
        ShippingService::ship(shippingItems);

        // Receipt
        cout << "** Checkout receipt **" << endl;
        for (auto& item : cart.getItems()) {
            cout << item.quantity << "x " << item.product->getName()
                << " " << item.product->getPrice() * item.quantity << endl;
            item.product->reduceQuantity(item.quantity);
        }
        cout << "----------------------" << endl;
        cout << "Subtotal " << subtotal << endl;
        cout << "Shipping " << shippingFee << endl;
        cout << "Amount " << total << endl;

        customer.deduct(total);
        cout << "Remaining Balance: " << customer.getRemainingBalance() << endl;

        for (auto& s : shippingItems) delete s;
        cart.clear();
    }
};

