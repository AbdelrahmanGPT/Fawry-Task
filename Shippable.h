#pragma once
#include <string>
using namespace std;

class Shippable {
public:
    virtual string getName() const = 0;
    virtual double getWeight() const = 0;
    virtual ~Shippable() = default;
};