#include "Product.h"
#include "Customer.h"
#include "Cart.h"
#include "CheckoutService.h"

int main() {
    
    // Products
    Product cheese("Cheese", 100, 5, true, true, 0.4);
    Product biscuits("Biscuits", 150, 2, true, true, 0.7);
    Product tv("TV", 300, 3, false, true, 10.0);
    Product scratchCard("ScratchCard", 50, 10, false, false);

    // Customer
    Customer ahmed("Ahmed", 500);

    // Cart
    Cart cart;
    cart.add(&cheese, 2);
    cart.add(&biscuits, 1);
    cart.add(&scratchCard, 1);

    // Checkout
    try {
        CheckoutService::checkout(ahmed, cart);
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}