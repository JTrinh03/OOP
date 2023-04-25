#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Light{
    public:
        void on(){
            cout << "Light is on" << endl;
        }
        void off(){
            cout << "Light is off" << endl;
        }
};

class TV{
    public:
        void on(){
            cout << "TV is on" << endl;
        }
        void off(){
            cout << "TV is off" << endl;
        }
        void setInputChanel(int i){
            cout<<"Turn to chanel "<<i<<endl;
        }
        void setVolume(int i){
            cout<<"Turn volume to "<<i<<endl;
        }
};

class Command{
    public:
        virtual void execute() = 0;
        virtual void undo() = 0;
 };

class LightOnCommand: public Command{
private:
    Light object;
public:
    LightOnCommand(const Light &object){
        this->object = object;
    }
    void execute(){
        this->object.on();
    }
    void undo(){
        this->object.off();
    }
};

class LightOffCommand: public Command{
private:
    Light object;
public:
    LightOffCommand(const Light &object){
        this->object = object;
    }
    void execute(){
        this->object.off();
    }
    void undo(){
        this->object.on();
    }
};

class TVonCommand: public Command{
private:
    TV object;
public:
    TVonCommand(const TV &object){
        this->object = object;
    }
    void execute(){
        this->object.on();
    }
    void undo(){
        this->object.off();
    }
};

class VolumeTVHighCommand: public Command{
private:
    TV object;
public:
    VolumeTVHighCommand(const TV &object){
        this->object = object;
    }
    void execute(){
        this->object.setVolume(50);
    }
    void undo(){
        this->object.setVolume(0);
    }
};

class NothingCommand: public Command{
public:
    void execute(){}
    void undo(){}
};

class Remote{
private:
    vector<Command*>onCommand;
    vector<Command*>offCommand;
public:
    Remote(){
        this->onCommand.reserve(3);
        this->offCommand.reserve(3);

        for(int i= 0; i<3; i++){
            onCommand[i] = new NothingCommand;
            offCommand[i] = new NothingCommand;
        }
    }

    ~Remote(){
        for(int i= 0; i<3; i++){
            delete onCommand[i];
            delete offCommand[i];
        }
    }

    void onButtonPressed(int number){
        if(number<=2 && number>=0){
            this->onCommand[number]->execute();
        }
    }

    void offButtonPressed(int number){
        if(number<=2 && number>=0){
            this->offCommand[number]->execute();
        }
    }

    void setCommand(Command *onCommand, Command *offCommand, int number){
        if(number <= 2 && number >= 0){
            this->onCommand[number] = onCommand;
            this->offCommand[number] = offCommand;
        }
    }
};

int main(){
    Remote myPhone;

    Light bedroomLight;
    TV livingroomTV;

    LightOnCommand bedroomLightOn(bedroomLight);
    LightOffCommand bedroomLightOff(bedroomLight);

    TVonCommand livingroomTVOn(livingroomTV);
    VolumeTVHighCommand livingroomTVHigh(livingroomTV);

    myPhone.setCommand(&bedroomLightOn, &bedroomLightOff, 0);
    myPhone.setCommand(&livingroomTVOn, &livingroomTVHigh, 1);

    myPhone.onButtonPressed(1);
    myPhone.offButtonPressed(1);

    myPhone.onButtonPressed(0);
    myPhone.offButtonPressed(0);

    return 0;
}

