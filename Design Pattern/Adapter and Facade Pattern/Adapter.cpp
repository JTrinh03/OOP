#include  <iostream>
#include  <string>
#include  <vector>

using namespace std;

class Iphone {
private:
    string cableType = "lightning";
public:
    Iphone() = default;
    ~Iphone() = default;

    string getCableType() const {
        return cableType;
    }

    virtual string solution() const {
        return "Charging requires Lightning-type cable.";
    }
};

class CableTypeC {
public:
    CableTypeC() = default;
    ~CableTypeC() = default;

    string rightCableSolution(const string& cableTest){
        if(cableTest == "typeC")
            return "[!] Charging complete.";
        else    
            return "[X] Charging failed. Wrong cable type.";
    }
};

class Adapter : public Iphone {
private:
    CableTypeC* cable;
public:
    Adapter(CableTypeC* cable) : cable(cable) {}
    ~Adapter() = default;

    string solution() const {
        if(getCableType() != "typeC")
            return cable->rightCableSolution("typeC");
        else   
            return cable->rightCableSolution(getCableType());
    }
};

void Client(const Iphone* clientsPhone){
    cout << clientsPhone->solution() << endl;
}

int main(){
    Iphone* clientsPhone = new Iphone;
    Client(clientsPhone);
    cout<<endl;

    CableTypeC* cable = new CableTypeC;
    cout << cable->rightCableSolution(clientsPhone->getCableType()) << endl;
    cout<<endl;

    Adapter* adapter = new Adapter(new CableTypeC);
    Client(adapter);

    return 0;
}