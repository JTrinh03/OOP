#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class IObserver{
    public:
        virtual ~IObserver(){};
        virtual void Update(string state) =0;
};
class ISubject{
    public:
        virtual ~ISubject(){};
        virtual void registerObserver(IObserver *observer)=0;
        virtual void removeObserver(IObserver *Observer)=0;
        virtual void notifyObserver()=0;
};
class Subject: public ISubject{
    private:
        list<IObserver*>list_observer;
        string state = "Default state";
    public:
        void registerObserver(IObserver *observer) override{
            list_observer.push_back(observer);
        }
        void removeObserver(IObserver *observer) override{
            list_observer.remove(observer);
        }
        void notifyObserver() override{
            list<IObserver*>::iterator iter = list_observer.begin();
            while(iter != list_observer.end()){
                (*iter)->Update(this->state);
                ++iter;
            }
        }
        void setState(string state){
            this->state = state;
            notifyObserver();
        }
        string getState(){
            return this->state;
        }
};

class Observer: public IObserver{
    private:
        string state;
        Subject &subject_;
        static int static_number;
        int number;
    public:
        Observer(Subject &subject) : subject_(subject){
            this->subject_.registerObserver(this);
            this->state = this->subject_.getState();
            this->number = Observer::static_number;
            ++Observer::static_number;
        }
        void Update(string state) override{
            this->state = state;
        }
        void Info(){
            cout <<"Observer "<<this->number<<" has state: "<<this->state <<endl;
        }
};

int Observer::static_number =1;
void check(vector <Observer*> ob_list, Subject* subject){
    cout <<"Current state of subject is: " <<(*subject).getState()<< endl;
    for(int i=0; i< ob_list.size(); i++){
        ob_list[i]->Info();
    }
    cout<<endl;
}

int main(){

    Subject *subject = new Subject();

    Observer *observer1 = new Observer(*subject);
    Observer *observer2 = new Observer(*subject);
    Observer *observer3 = new Observer(*subject);

    vector<Observer*> observer_list{observer1,observer2, observer3};
    check(observer_list, subject);

    subject->setState("Sehr Gut");
    check(observer_list, subject);

    Observer *observer4 = new Observer(*subject);
    observer_list.push_back(observer4);
    check(observer_list, subject);

    subject->removeObserver(observer2);
    subject->setState("So So");
    check(observer_list, subject);

    subject->removeObserver(observer3);
    Observer *observer5 = new Observer(*subject);
    observer_list.push_back(observer5);
    subject->setState("Perfect");
    check(observer_list, subject);
}
