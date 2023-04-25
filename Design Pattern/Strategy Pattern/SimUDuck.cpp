#include <iostream>
#include <string>

using namespace std;
// interface for fly methods
class FlyBehavior {
public:
    virtual void DoFly(){};
};


class FlyWithWings : public FlyBehavior {
public:
    void DoFly() {
        cout << "I'm flying with wings!" << endl;
    }
};

class FlyNoWay : public FlyBehavior {
public:
    void DoFly() override{
        cout << "I can't fly!" << endl;
    }
};

class QuackBehavior {
public:
    virtual void DoQuack() {};
};

class Quack : public QuackBehavior {
public:
    void DoQuack() override {
        cout << "Quack!" << endl;
    }
};

class Squeak : public QuackBehavior {
public:
    void DoQuack() override {
        cout << "Squeak!" << endl;
    }
};

class CannotQuack : public QuackBehavior {
public:
    void DoQuack() override {
        cout << "I can't quack!" << endl;
    }
};

//base clas for ducks
class Duck {
public:
    QuackBehavior *quackBehavior;
    FlyBehavior *flyBehavior;

    void SetFlyBehavior(FlyBehavior *flybehavior) {
        flyBehavior = flybehavior;
    }
    void PerformFly() {
        flyBehavior->DoFly();
    }

    void PerformQuack() {
        quackBehavior->DoQuack();
    }

    virtual void Display() = 0;
};

class MallardDuck : public Duck{
public:
    MallardDuck(){
        quackBehavior = new Quack;
        flyBehavior = new FlyWithWings;
    }

    void Display(){
        cout<<"I'm a Mallard Duck!"<<endl;
    }
};

class DecoyDuck : public Duck{
public:
    DecoyDuck(){
        quackBehavior = new CannotQuack;
        flyBehavior = new FlyNoWay;
    }

    void Display(){
        cout<<"I'm a Decoy Duck!"<<endl;
    }
};


int main(int argc, char *argv[]){
    Duck* mallard = new MallardDuck();
    mallard->Display();
    mallard->PerformFly();
    mallard->PerformQuack();
    mallard->SetFlyBehavior(new FlyNoWay);
    mallard->PerformFly();
    cout << endl;

    Duck* decoy = new DecoyDuck();
    decoy->Display();
    decoy->PerformFly();
    decoy->PerformQuack();
    cout << endl;
}
