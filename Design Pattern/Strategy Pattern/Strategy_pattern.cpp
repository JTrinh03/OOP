#include <iostream>
#include <string>

using namespace std;

class PricingStrategy {
public:
    virtual float calculatePrice(float basePrice) = 0;
};

class RegularPricing : public PricingStrategy {
public:
    float calculatePrice(float basePrice) override {
        return basePrice;
    }
};

class DiscountPricing : public PricingStrategy {
public:
    float calculatePrice(float basePrice) override {
        return basePrice * 0.9f; // apply 10% discount
    }
};

class HolidayPricing : public PricingStrategy {
public:
    float calculatePrice(float basePrice) override {
        return basePrice * 0.8f; // apply 20% discount
    }
};

class Website {
private:
    PricingStrategy* strategy;

public:
    Website(PricingStrategy* strategy) : strategy(strategy) {}

    void setStrategy(PricingStrategy* strategy) {
        this->strategy = strategy;
    }

    float calculatePrice(float basePrice) {
        return strategy->calculatePrice(basePrice);
    }
};

int main() {
    Website website(new RegularPricing()); 

    float price1 = website.calculatePrice(100.0f);
    std::cout << "Regular price: " << price1 << std::endl;

    website.setStrategy(new DiscountPricing());
    float price2 = website.calculatePrice(100.0f);
    std::cout << "Discounted price: " << price2 << std::endl;

    website.setStrategy(new HolidayPricing());
    float price3 = website.calculatePrice(100.0f);
    std::cout << "Holiday price: " << price3 << std::endl;

    return 0;
}
