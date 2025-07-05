#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "Shippable.h"
using namespace std;

class ShippingService {
public:
    static void ship(const vector<Shippable*>& items) {
        if (items.empty()) return;

        cout << "** Shipment notice **" << endl;
        double totalWeight = 0.0;
        for (auto& item : items) {
            cout << item->getName() << endl;
            totalWeight += item->getWeight();
        }
        cout << "Total package weight " << fixed << setprecision(1) << totalWeight << "kg" << endl << endl;
    }
};

