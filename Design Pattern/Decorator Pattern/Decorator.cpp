#include <iostream>
#include <string>

using namespace std;

class Beverage{
protected:
    string description{};
public:
    virtual string getDescription(){
        return description;
    }

    virtual double cost() = 0;
};

class Espresso : public Beverage{
public:
    Espresso(){
        description = "Espresso";
    }

    double cost() override{
        return 1.99;
    }
};

class HouseBlend : public Beverage{
public:
    HouseBlend(){
        description = "House Blend Coffee";
    }

    double cost() override{
        return 0.89;
    }
};

class CondimentDecorator : public Beverage{
public:
    virtual string getDescription() = 0;
};

class Mocha : public CondimentDecorator{
private:
    Beverage* beverage{};
public:
    Mocha(Beverage* beverage){
        this->beverage = beverage;
    }

    string getDescription() override{
        return beverage->getDescription() + ", Mocha";
    }

    double cost() override{
        return 0.20 + beverage->cost();
    }
};

class Whip : public CondimentDecorator{
private:
    Beverage* beverage{};
public:
    Whip(Beverage* beverage){
        this->beverage = beverage;
    }

    string getDescription() override{
        return beverage->getDescription() + ", Whip";
    }

    double cost() override{
        return 0.10 + beverage->cost();
    }
};

int main(){
    Beverage* order1 = new Espresso();
    order1 = new Mocha(order1);
    order1 = new Mocha(order1);
    order1 = new Whip(order1);
    cout<< order1->getDescription() << ": $" << order1->cost() << endl;

    Beverage* order2 = new HouseBlend();
    order2 = new Whip(order2);
    cout<< order2->getDescription() << ": $" << order2->cost() << endl;

    return 0;
}