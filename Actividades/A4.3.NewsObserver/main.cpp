#include <iostream>
#include <vector>
using namespace std;

class  Observer{
public:
    virtual void update()=0;
};

class Subject{
public:
     virtual void sub(Observer)=0;
     virtual void unsub(Observer)=0;
     virtual void notify()=0;
};

class Candidato: public Subject{
public:
    string name;
    Candidato(){};
    Candidato(string n){
        name=n;
    }
    vector<Observer*> subs;
    void sub(Observer *nws)
    {
        subs.push_back(nws);
    }
    void unsub(Observer *nws){
        for(int i=0;i<subs.size();i++){
            if(subs[i]==nws)
            {
                subs.erase(subs.begin()+i);
            }
        }
    }
    void notify(string message){
        for(int i=0;i<subs.size();i++){
            string spesificMessage;
            message=name+" twittio "+message;
            subs[i]->update();
        }
    }
};

class NN:public Observer{
public:
    string name;
    NN(){}
    NN(string n){
        name=n;
    }
    void update(string message){
        cout<<name<<"reporta:"<<message;
    }
};
class MVS:public NN{
public:
    MVS(){name="MVS";}
    void update(string message){
        cout<<name<<"reporta:"<<message;
    }
};
class TelV:public NN{
public:
    TelV(){name="Telvisa";}
    void update(string message){
        cout<<name<<"reporta:"<<message;
    }
};
class Azt:public NN{
public:
    Azt(){name="Aztec";}
    void update(string message){
        cout<<name<<"reporta:"<<message;
    }
};
class Trump:public Candidato{
public:
    Trump(){name="Trump";}
    vector<Observer*> subs;
    void sub(Observer *nws)
    {
        subs.push_back(nws);
    }
    void unsub(Observer *nws){
        for(int i=0;i<subs.size();i++){
            if(subs[i]==nws)
            {
                subs.erase(subs.begin()+i);
            }
        }
    }
    void notify(string message){
        for(int i=0;i<subs.size();i++){
            string spesificMessage;
            message=name+" twittio "+message;
            subs[i]->update();
        }
    }

};
class Anaya:public Candidato{
public:
    Anaya(){name="Anaya";}
    vector<Observer*> subs;
    void sub(Observer *nws)
    {
        subs.push_back(nws);
    }
    void unsub(Observer *nws){
        for(int i=0;i<subs.size();i++){
            if(subs[i]==nws)
            {
                subs.erase(subs.begin()+i);
            }
        }
    }
    void notify(string message){
        for(int i=0;i<subs.size();i++){
            string spesificMessage;
            message=name+" twittio "+message;
            subs[i]->update();
        }
    }
};
class Meade:public Candidato{
public:
    Meade(){name="Meade";}
    vector<Observer*> subs;
    void sub(Observer *nws)
    {
        subs.push_back(nws);
    }
    void unsub(Observer *nws){
        for(int i=0;i<subs.size();i++){
            if(subs[i]==nws)
            {
                subs.erase(subs.begin()+i);
            }
        }
    }
    void notify(string message){
        for(int i=0;i<subs.size();i++){
            string spesificMessage;
            message=name+" twittio "+message;
            subs[i]->update();
        }
    }
};
class Amlo:public Candidato{
public:
    Amlo(){name="Amlo";}
    vector<Observer*> subs;
    void sub(Observer *nws)
    {
        subs.push_back(nws);
    }
    void unsub(Observer *nws){
        for(int i=0;i<subs.size();i++){
            if(subs[i]==nws)
            {
                subs.erase(subs.begin()+i);
            }
        }
    }
    void notify(string message){
        for(int i=0;i<subs.size();i++){
            string spesificMessage;
            message=name+" twittio "+message;
            subs[i]->update();
        }
    }
};

int main() {
    Trump T;
    Anaya An;
    Meade Me;
    Amlo Am;
    MVS *Mv;
    TelV *Te;
    Azt* Az;
    T.sub(Mv);
    An.sub(Te);
    An.sub(Az);
    Me.sub(Te);
    Me.sub(Az);
    Am.sub(Te);
    Am.sub(Az);


    T.notify("i like dogs");

};